#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int FIFO(int np, int nf, int fault, int pages[], int frames[])
{
    printf("FIFO: \n");
    int i, j, count=0;

    for(i=0;i<np;i++){
        int found = 0;
        for(j=0;j<nf;j++){
            if(frames[j]==pages[i]){
                found=1;
                break;
            }
        }
        if(found==0){
            frames[count]=pages[i];
            count=(count+1)%nf;
            fault++;
        }
    }
    return fault;
}

int Optimal(int np, int nf, int fault, int pages[], int frames[])
{
    printf("Optimal: \n");
    int i, j, k, max, idx, found = 0;
    
    int next[np];
    
    for (i = 0; i < np; i++)
    {
        found = 0;
        for (j = 0; j < nf; j++)
        {
            if (frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            if (i < nf)
            {
                frames[i] = pages[i];
                fault++;
            }
            else
            {
                for (j = 0; j < nf; j++)
                {
                    next[j] = -1;
                    for (k = i + 1; k < np; k++)
                    {
                        if (pages[k] == frames[j])
                        {
                            next[j] = k;
                            break;
                        }
                    }
                }
                max = -1;
                idx = -1;
                for (j = 0; j < nf; j++)
                {
                    if (next[j] == -1)
                    {
                        idx = j;
                        break;
                    }
                    else
                    {
                        if (next[j] > max)
                        {
                            max = next[j];
                            idx = j;
                        }
                    }
                }
                frames[idx] = pages[i];
                fault++;
            }
        }
    }
    return fault;
}

int LRU(int np, int nf, int fault, int pages[], int frames[], int flag[])
{
    printf("Least Recently Used:\n");
    int i, j, min, idx, found = 0;
    
    for (i = 0; i < np; i++)
    {
        found = 0;
        for (j = 0; j < nf; j++)
        {
            if (frames[j] == pages[i])
            {
                found = 1;
                flag[j] = i + 1;
                break;
            }
        }
        if (found == 0)
        {
            min = INT_MAX;
            for (j = 0; j < nf; j++)
            {
                if (flag[j] < min)
                {
                    min = flag[j];
                    idx = j;
                }
            }
            frames[idx] = pages[i];
            flag[idx] = i + 1;
            fault++;
        }
    }
    return fault;
}

int Second_chance(int np, int nf, int fault, int pages[], int frames[], int flag[])
{
    printf("Second Chance: \n");
    int i, j, found = 0, ref_bit = 0;
    
    for (i = 0; i < np; i++)
    {
        found = 0;
        ref_bit = 0;
        for (j = 0; j < nf; j++)
        {
            if (frames[j] == pages[i])
            {
                found = 1;
                flag[j] = 1;
                break;
            }
        }
        if (found == 0)
        {
            int replaced = 0;
            while (replaced == 0)
            {
                for (j = 0; j < nf; j++)
                {
                    if (flag[j] == 0)
                    {
                        frames[j] = pages[i];
                        flag[j] = 1;
                        replaced = 1;
                        fault++;
                        break;
                    }
                    else
                    {
                        flag[j] = 0;
                        if ((pages[i] == frames[j]) && (ref_bit == 0))
                        {
                            flag[j] = 1;
                            ref_bit = 1;
                        }
                    }
                }
            }
        }
    }
    return fault;
}

int main()
{
    int i, j, np, nf, fault = 0, count = 0;
    printf("Enter the length of ref string(number of pages): ");
    scanf("%d", &np);

    int pages[np];
    printf("Enter the reference string: ");
    for (i = 0; i < np; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &nf);

    int frames[nf], flag[nf];
    for (i = 0; i < nf; i++)
    {
        frames[i] = -1;
        flag[i] = 0;
    }

    int choice;
    printf("Enter the choice of Page Replacement Algorithm: \n");
    printf("\t1. FIFO\n\t2. Optimal \n\t3. Least Recently Used \n\t4. Second Chance\n");
    scanf("%d", &choice);

    int pageFaults;
    switch (choice)
    {
    case (1):
        pageFaults = FIFO(np, nf, fault, pages, frames);
        break;

    case (2):
        pageFaults = Optimal(np, nf, fault, pages, frames);
        break;

    case (3):
        pageFaults = LRU(np, nf, fault, pages, frames, flag);
        break;

    case (4):
        pageFaults = Second_chance(np, nf, fault, pages, frames, flag);
        break;
    }

    int pageHits = np - pageFaults;
    printf("Total Page Faults: %d\n", pageFaults);
    printf("Total Page Hits: %d\n", pageHits);

    return 0;
}