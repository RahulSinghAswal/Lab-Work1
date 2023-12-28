// Banker's Algorithm

#include <stdio.h>
// #include <conio.h>

struct da
{
    int max[10], a1[10], need[10], before[10], after[10];

}

p[10];

void main()
{
    // declare all required variables
    int i, j, k, l, r, n, tot[10], av[10], cn = 0, temp = 0, cz = 0, c = 0;

    // clrscr();

    // taking no. of processes
    printf("\nEnter the no. of processes");
    scanf("%d", &n);

    // taking no. of resources
    printf("\nEnter the no. of resources");
    scanf("%d", &r);

    // taking maximum value for resource
    // taking allocated from resource
    for (i = 0; i < n; i++)
    {
        printf("\nProcess %d\n", i + 1);
        for (j = 0; j < r; j++)
        {
            printf("Maximum value for resource %d:", j + 1);
            scanf("%d", &p[i].max[j]);
        }
        printf("\n");

        for (j = 0; j < r; j++)
        {
            printf("Alocated from resource %d :", j + 1);
            scanf("%d", &p[i].a1[j]);
            p[i].need[j] = p[i].max[j] - p[i].a1[j];
        }
    }

    // taking total value of resource
    for (i = 0; i < r; i++)
    {
        printf("\nEnter total value of resource %d:", i + 1);
        scanf("%d", &tot[i]);
    }



    for (i = 0; i < r; i++)
    {
        for (j = 0; j < n; j++)
        {
            temp = temp + p[j].a1[i];
            av[i] = tot[i] - temp;
            temp = 0;
        }
    }

    // print table heading
    printf("\n\tResources Allocated Needed  Total Avail");
    for (i = 0; i < n; i++)
    {
        printf("\n P %d \t", i + 1);
        for (j = 0; j < r; j++)
        {
            printf("%d", p[i].max[j]);

        }
            printf("\t");
            for (j = 0; j < r; j++)
            {
                printf("%d", p[i].a1[j]);
            }
                printf("\t");
            

            for (j = 0; j < r; j++)
            {
                printf("%d", p[i].need[j]);
            }
                printf("\t");
            


            for (j = 0; j < r; j++)
            {
                if (i == 0)
                {
                    printf("%d", tot[j]);
                }
            }
            printf("    ");
            for (j = 0; j < r; j++)
            {
                if (i == 0)
                {
                    printf("%d", av[j]);
                }
            }
        }

        // print headings
        printf("\n\n Avail Before \t Avail After ");
        for (l = 0; i < n; l++)
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < r; j++)
                {
                    if (p[i].need[j] > av[j])
                    {
                        cn++;
                    }
                    if (p[i].max[j] == 0)
                    {
                        cz++;
                    }
                }
                if (cn == 0 && cz != r)
                {
                    for (j = 0; j < r; j++)
                    {
                        p[i].before[j] = av[j] - p[i].need[j];
                        p[i].after[j] = p[i].before[j] + p[i].max[j];
                        av[j] = p[i].after[j];
                        p[i].max[j] = 0;
                    }
                    printf("\n P %d \t", i + 1);
                    for (j = 0; j < r; j++)
                    {
                        printf("%d", p[i].before[j]);
                        printf("\t");
                        for (j = 0; j < r; j++)
                        {
                            printf("%d", p[i].after[j]);
                            cn = 0;
                            cz = 0;
                            c++;
                            break;
                        }

                       } 
                }

                        else
                        {
                            cn = 0;
                            cz = 0;
                        }
                    }
                }
                if (c == n)
                {
                    printf("\n The above sequence is a Safe Sequence");
                }
                else
                {
                    printf("\n DeadLock Occured");
                }

                // getch();
            }
        
    
