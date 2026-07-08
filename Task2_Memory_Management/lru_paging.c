#include <stdio.h>

#define FRAMES 3
#define PAGES 10

int main()
{
    int referenceString[PAGES] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3};

    int frames[FRAMES];
    int lastUsed[FRAMES];

    int pageFaults = 0;

    for(int i = 0; i < FRAMES; i++)
    {
        frames[i] = -1;
        lastUsed[i] = -1;
    }

    printf("LRU Page Replacement Simulation\n\n");

    for(int time = 0; time < PAGES; time++)
    {
        int page = referenceString[time];
        int hit = 0;

        for(int j = 0; j < FRAMES; j++)
        {
            if(frames[j] == page)
            {
                hit = 1;
                lastUsed[j] = time;
                break;
            }
        }

        if(!hit)
        {
            int replaceIndex = 0;

            for(int j = 1; j < FRAMES; j++)
            {
                if(lastUsed[j] < lastUsed[replaceIndex])
                {
                    replaceIndex = j;
                }
            }

            frames[replaceIndex] = page;
            lastUsed[replaceIndex] = time;
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
