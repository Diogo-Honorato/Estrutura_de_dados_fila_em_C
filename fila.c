#include <stdio.h>
#include <stdlib.h>

typedef struct Cell
{
    char *name;
    struct Cell *next;
    struct Cell *prev;
} Cell;

typedef struct
{
    Cell *first;
    Cell *last;
    int size;
} Queue;

Queue *AllocateQueue()
{
    return (Queue *)malloc(sizeof(Queue));
}

void StartQueue(Queue *cell)
{
    cell->first = NULL;
    cell->last = NULL;
    cell->size = 0;
}

int InsertQueue(Queue *cell, char *name)
{
    Cell *newcell = (Cell *)malloc(sizeof(Cell));
    newcell->name = name;
    newcell->next = NULL;
    newcell->prev = NULL;

    if (cell->first == NULL)
    {
        cell->first = newcell;
    }
    else
    {
        cell->last->next = newcell;
        newcell->prev = cell->last;
    }
    cell->last = newcell;
    cell->size++;

    return 1;
}

int RemoveQueue(Queue *cell)
{
    if (cell->size == 0)
    {
        printf("\n\nEmpty queue!\n\n");
        exit(0);
    }

    Cell *aux = cell->first;

    cell->first = cell->first->next;

    printf("\nItem removed: %s\n", aux->name);

    free(aux);

    return 1;
}

int PrintQueue(Queue *cell)
{
    if (cell->size == 0)
    {
        printf("\n\nEmpty queue!\n\n");
    }
    else
    {
        printf("\nQueue:\n");
        Cell *aux = cell->first;

        while (aux != NULL)
        {
            printf("(%s) ", aux->name);
            aux = aux->next;
        }
    }
    printf("\n");

    return 1;
}

int main()
{
    Queue *cell = AllocateQueue();
    char list[11][20] = {"Ana","Bruno","diogo","Carla","Daniel","Elena","Fernando","Gabriela","Hugo","Isabela","João"};

    StartQueue(cell);

    for(int i = 0;i < 11 ;i++)
    {
        InsertQueue(cell,list[i]);
    }
    PrintQueue(cell);
    RemoveQueue(cell);
    RemoveQueue(cell);
    PrintQueue(cell);
}
