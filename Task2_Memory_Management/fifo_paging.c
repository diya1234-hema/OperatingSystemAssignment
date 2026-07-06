#include <stdio.h>

#define FRAMES 3
#define PAGES 10

int main()
{
    int referenceString[PAGES] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3};

    int frames[FRAMES];
    int pageFaults = 0;

    for(int i = 0; i < FRAMES; i++)
    {
        frames[i] = -1;
    }

    int fifoIndex = 0;

    printf("FIFO Page Replacement Simulation\n\n");

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

        if(!hit)
        {
            frames[fifoIndex] = page;
            fifoIndex = (fifoIndex + 1) % FRAMES;
            pageFaults++;
        }

        printf("Page %d -> Frames: ", page);

        for(int j = 0; j < FRAMES; j++)
        {
            printf("%d ", frames[j]);
        }

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}
