#!/usr/bin/python3

import os
import sys
import timeit

def run(number, tp, t=None):
    tm = 0
    if t:
        test = "cat {}/{}".format(os.getcwd(), t)
        print("INPUT:")
        os.system(test)
        test += ' | '
        print("\nOUTPUT")
    else:
        test = ""
    if tp == "python":
        prog = "{}/{}/{}.py".format(os.getcwd(), tp, number)
        command = "{}python3 {}"
        command = command.format(test, prog)
        tm = timeit.timeit(lambda: os.system(command), number=1)
    elif tp == "cpp":
        prog = "{}/{}/{}".format(os.getcwd(), tp, number)
        command = "g++ -fno-strict-aliasing -DONLINE_JUDGE -lm -s -x c++ -std=c++14 -O2 {}.cpp -o {}"
        command = command.format(prog, prog)
        os.system(command)
        command = "{}{}".format(test, prog)
        tm = timeit.timeit(lambda: os.system(command), number=1)
        command = "rm {}".format(prog)
    print("\nTIME: {}s\n".format(tm))

def main():
    number = ""
    tasks = os.listdir(os.getcwd())
    if len(sys.argv) > 1:
        if not sys.argv[1].isdigit():
            print("\"{}\" - Not a number of task!".format(number))
        elif sys.argv[1] not in tasks:
            print("No task number {}!".format(number))
        else:
            number = sys.argv[1]
    while not number:
        temp = input("Input number of task?: ")
        if not temp.isdigit():
            print("\"{}\" - Not a number of task!".format(temp))
        elif temp not in tasks:
            print("No task number {}!".format(temp))
        else:
            number = temp
    os.chdir(number)
    temp = os.listdir(os.getcwd())
    tests = [i for i in temp if os.path.isfile(i)]
    languages = [i for i in temp if os.path.isdir(i)]
    tp = ""
    if len(sys.argv) > 2:
        if sys.argv[2] in languages:
            tp = sys.argv[2]
        else:
            print("No such type \"{}\"".format(sys.argv[2]))
    while not tp:
        print("Languages for task {}:\n\tNum\tType".format(number))
        for i in range(len(languages)):
            print("\t{}:\t{}".format(i, languages[i]))
        temp = input("Input type/number:")
        if temp in languages:
            tp = temp
        elif temp.isdigit() and (0 <= int(temp) < len(languages)):
            tp = languages[int(temp)]
        else:
            print("No such type \"{}\"".format(temp))
    for t in tests:
        print("Start test \"{}\" for task \"{}\" in \"{}\":\n".format(t, number, tp))
        run(number, tp, t)
    print("Start tast \"{}\" in \"{}\" for your test:".format(number, tp))
    run(number, tp)
    

if __name__ == "__main__":
    main()
