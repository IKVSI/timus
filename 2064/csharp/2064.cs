using System;
using System.Text;

class Program
{
    static int ReadInt()
    {
        char ch = (char) 0;
        int ret = 0;
        while (true)
        {
            ch = (char) Console.Read();
            if ((ch >= '0') && (ch <= '9')) ret = ret*10 + ch-'0';
            if ((ret != 0) && ((ch == ' ') || (ch == '\n'))) break;
        }
        return ret;
    }
    static void Main()
    {
        int[] t = new int [int.Parse(Console.ReadLine())];
        for(int i=0; i<t.Length; ++i) t[i] = ReadInt();
        Array.Sort(t);
        Array.Reverse(t);
        int k = 0;
        for (int a = 1; a < t.Length; ++a)
        {
            if (t[k] != t[a])
            {
                ++k;
                t[k] = t[a];
            }
        }
        ++k;
        StringBuilder sb = new StringBuilder();
        int q = int.Parse(Console.ReadLine());
        int t0 = t[0];
        for ( int i=0; i<q; ++i)
        {
            int x = int.Parse(Console.ReadLine());
            if (x <= t0)
            {
                sb.Append(x.ToString());
                sb.Append("\n");
                continue;
            }
            int mx = 0;
            for (int j = 0; j < k; ++j)
            {
                int tj = t[j];
                if (mx >= tj) break;
                int temp1 = x/tj, temp2 = x-temp1*tj, r;
                if (temp1%2 == 1) r = tj - temp2;
                else r = temp2;
                if (r > mx) mx = r;
            }
            sb.Append(mx.ToString());
            sb.Append("\n");
        }
        sb.Length--;
        Console.WriteLine(sb.ToString());
    }
}