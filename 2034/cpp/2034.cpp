#include <iostream>

struct List
{
    unsigned long v;
    List* next;
};

void findway(unsigned long V, List** &pred, unsigned long * &length, List ** &edges)
{
    List* queueS = new List;
    queueS->v = V;
    queueS->next = nullptr;
    List* queueF = queueS;
    length[V] = 0;
    while (queueS != nullptr)
    {
        //std::cout <<queueS->v << '\n';
        for (List* a = edges[queueS->v]; a; a = a->next)
        {
            if (length[a->v] >= (length[queueS->v] + 1))
            {
                List* b = new List;
                b->v = queueS->v;
                b->next = pred[a->v];
                pred[a->v] = b;
                if (length[a->v] > (length[queueS->v] + 1))
                {
                    List* c = new List;
                    c->v = a->v;
                    c->next = nullptr;
                    queueF->next = c;
                    queueF = c;
                    length[a->v] = length[queueS->v] + 1;
                }
            }
        }
        List * a = queueS;
        queueS = queueS->next;
        delete a;
    }
}

int main()
{
    unsigned long N, M;
    std::cin >> N >> M;
    List ** edges = new List * [N];
    for (unsigned long i = 0; i < N; ++i) edges[i] = nullptr;
    for (unsigned long i = 0; i < M; ++i)
    {
        List* a = new List;
        List* b = new List;
        std::cin >> b->v >> a->v;
        --b->v;
        --a->v;
        a->next = edges[b->v];
        edges[b->v] = a;
        b->next = edges[a->v];
        edges[a->v] = b;
    }
    unsigned long S, F, R;
    std::cin >> S >> F >> R;
    --S;
    --F;
    --R;
    /*
    std::cout << "S: " << S << " F: " << F << " R: " << R << '\n';
    for(unsigned long i = 0; i < N; ++i)
    {
        std::cout << i << ": ";
        for(List * a = edges[i]; a; a = a->next)
        {
            std::cout << a->v << ' ';
        }
        std::cout << '\n';
    }
    */

    List** predS = new List * [N];
    for (unsigned long i = 0; i < N; ++i) predS[i] = nullptr;
    unsigned long* lengthS = new unsigned long[N];
    for (unsigned long i = 0; i < N; ++i) lengthS[i] = N + 1;
    findway(S, predS, lengthS, edges);
    /*
    for(unsigned long i = 0; i < N; ++i)
    {
        std::cout << i << "(" << lengthS[i] << "): ";
        for(List * a = predS[i]; a; a = a->next)
        {
            std::cout << a->v << ' ';
        }
        std::cout << '\n';
    }
    */

    List** predR = new List * [N];
    for (unsigned long i = 0; i < N; ++i) predR[i] = nullptr;
    unsigned long* lengthR = new unsigned long[N];
    for (unsigned long i = 0; i < N; ++i) lengthR[i] = N + 1;
    findway(R, predR, lengthR, edges);
    /*
    for(unsigned long i = 0; i < N; ++i)
    {
        std::cout << i << "(" << lengthR[i] << "): ";
        for(List * a = predR[i]; a; a = a->next)
        {
            std::cout << a->v << ' ';
        }
        std::cout << '\n';
    }
    */
    unsigned long pathlength = lengthS[F] + 1;
    unsigned long * path = new unsigned long [pathlength];
    unsigned long * pathL = new unsigned long [pathlength]; 
    unsigned long cursor = 0;
    path[cursor] = F;
    pathL[cursor] = lengthR[F];
    unsigned long length = 0;
    while ((length < lengthR[S]) && (length < lengthR[F]))
    {
        if (path[cursor] == S)
        {
            if (length < pathL[cursor]) length = pathL[cursor];
            if (pathL[cursor] == pathL[0]) break;
            while(length == pathL[cursor]) --cursor;
        }
        else
        {
            if (predS[path[cursor]] == nullptr)
            {
                if (cursor == 0) break;
                --cursor;
                List * a = predS[path[cursor]];
                predS[path[cursor]] = predS[path[cursor]]->next;
                delete a;
            }
            else if (lengthR[predS[path[cursor]]->v] <= length)
            {
                List * a = predS[path[cursor]];
                predS[path[cursor]] = predS[path[cursor]]->next;
                delete a;
            }
            else
            {
                ++cursor;
                path[cursor] = predS[path[cursor - 1]]->v;
                pathL[cursor] = (pathL[cursor - 1] > lengthR[path[cursor]]) ? lengthR[path[cursor]] : pathL[cursor - 1];
            }
        }
    } 
    std::cout << length;

    delete [] path;
    delete [] pathL;
    for (unsigned long i = 0; i < N; ++i)
    {
        List* a = edges[i];
        while (a)
        {
            List* b = a;
            a = b->next;
            delete b;
        }
        a = predS[i];
        while (a)
        {
            List* b = a;
            a = b->next;
            delete b;
        }
        a = predR[i];
        while (a)
        {
            List* b = a;
            a = b->next;
            delete b;
        }
    }
    delete[] edges;
    delete[] predS;
    delete[] lengthS;
    delete[] predR;
    delete[] lengthR;
    return 0;
}