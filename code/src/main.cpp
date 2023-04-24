#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <iostream>
#include <unistd.h> /* read, write, pipe, _exit */
#include <string.h>

#include "dplib.h"


using namespace std;

/* Flag set by ‘--verbose’. */
static int verbose_flag;



void displayUsage()
{
    cout <<
            "-n/--number <n>:       Number 'n'. <Default: 5>\n"
            "-h/--help:             Show help\n";
    exit(EXIT_SUCCESS);
}

int main (int argc, char **argv)
{
    int c;
    int n = 5;
    string input1;
    string input2;

    while (true)
    {
        static struct option long_options[] =
        {
            /* These options set a flag. */
            {"verbose", no_argument,       &verbose_flag, 1},
            {"brief",   no_argument,       &verbose_flag, 0},
            /* These options don’t set a flag.
                We distinguish them by their indices. */
            {"input",       required_argument,  0,  'i'}, 
            {"algorithm",   required_argument,  0,  'a'}, 
            {"number",      required_argument,  0,  'n'},  
            {"help",        no_argument,        0,  'h'}, 
            {0, 0, 0, 0}
        };

        /* getopt_long stores the option index here. */
        int option_index = 0;

        c = getopt_long (argc, argv, "hn:i:a:",
                        long_options, &option_index);

      

        /* Detect the end of the options. */
        if (c == -1)
            break;

        switch (c)
        {
            case 0:
                /* If this option set a flag, do nothing else now. */
                if (long_options[option_index].flag != 0)
                    break;
                printf ("option %s", long_options[option_index].name);
                if (optarg)
                    printf (" with arg %s", optarg);
                printf ("\n");
                break;
            case 'a':
                if(strcmp(optarg,"lcs")==0)
                {
                    cout << "Least Common String" << endl;
                    dplib  dp;
                    int size1 = input1.length();
                    int size2 = input2.length();
                    int result = dp.lcs(input1,input2,size1,size2);
                    cout << "Length of LCS is " <<result << endl;
                }
                break;
            case 'i':
            {
                string input = optarg;
                size_t pos = 0;
                pos = input.find(",");
                if (pos == string::npos) {
                    cerr << "Error: Invalid input format. Must be in the format \"input1,input2\"" << endl;
                    break;
                }
                input1 = input.substr(0, pos);
                input2 = input.substr(pos+1);
                cout << "Inputs: " <<input1 <<" - "<<input2<< endl;
                break;
            }
            case 'n':      
                n = atoi(optarg);                
                break;
            case 'h':
            case '?':
            default:
                displayUsage();
                abort ();
        }
    }

    /* Instead of reporting ‘--verbose’
    and ‘--brief’ as they are encountered,
    we report the final status resulting from them. */
    if (verbose_flag)
        puts ("verbose flag is set");

    /* Print any remaining command line arguments (not options). */
    if (optind < argc)
    {
        printf ("non-option ARGV-elements: ");
        while (optind < argc)
            printf ("%s ", argv[optind++]);
        putchar ('\n');
    }

    std::cout<<"DP Exercises"<<std::endl;


    exit (EXIT_SUCCESS);
}