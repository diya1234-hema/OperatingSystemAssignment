#include <stdio.h>

#define FRAMES 3
#define PAGES 10

int main()
{
    int referenceString[PAGES] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3};

    int frames[FRAMES];

    int pageFaults = 0;
    int hits = 0;
    int misses = 0;

    for(int i = 0; i < FRAMES; i++)
    {
        frames[i] = -1;
    }

    int fifoIndex = 0;

    printf("Paging Analysis Simulation\n\n");

    for(int i = 0; i < PAGES; i++)
    {
        int page = referenceString[i];
        int hit = 0;

        for(int j = 0; j < FRAMES; j++)
        {
            if(frames[j] == page)
            {
                hit = 1;
                break;
            }
        }

        if(hit)
        {
            hits++;
            printf("Page %d -> HIT\n", page);
        }
        else
        {
            misses++;
            pageFaults++;

            frames[fifoIndex] = page;
            fifoIndex = (fifoIndex + 1) % FRAMES;

            printf("Page %d -> MISS\n", page);
        }

        printf("Frames: ");

        for(int j = 0; j < FRAMES; j++)
        {
            printf("%d ", frames[j]);
        }

        printf("\n\n");
    }

    double hitRatio = (double)hits / PAGES;
    double missRatio = (double)misses / PAGES;

    printf("Total Hits = %d\n", hits);
    printf("Total Misses = %d\n", misses);
    printf("Total Page Faults = %d\n", pageFaults);
    printf("Hit Ratio = %.2f\n", hitRatio);
    printf("Miss Ratio = %.2f\n", missRatio);

    return 0;
}
