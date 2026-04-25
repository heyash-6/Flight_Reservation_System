#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int  bookingId;
    char name[50];
    char flightNo[15];
    char from[20];
    char to[20];
    char date[15];
    char seat[6];
    char travelClass[10];

    struct node *prev;
    struct node *next;
}node;

typedef struct
{
    node *start;
    int   count;
    int   nextId;
}LL;

void insertbegin(LL *l, char name[], char flightNo[],
                 char from[], char to[], char date[],
                 char seat[], char travelClass[])
{
    node *newrec;
    newrec = (node*)malloc(sizeof(node));

    newrec->bookingId = l->nextId++;
    strcpy(newrec->name,        name);
    strcpy(newrec->flightNo,    flightNo);
    strcpy(newrec->from,        from);
    strcpy(newrec->to,          to);
    strcpy(newrec->date,        date);
    strcpy(newrec->seat,        seat);
    strcpy(newrec->travelClass, travelClass);
    newrec->prev = NULL;
    newrec->next = NULL;

    if(l->start == NULL)
    {
        l->start = newrec;
    }
    else
    {
        newrec->next   = l->start;
        l->start->prev = newrec;
        l->start       = newrec;
    }

    l->count++;
    printf("\nReservation added at beginning. Booking ID = %d", newrec->bookingId);
}

void insertend(LL *l, char name[], char flightNo[],
               char from[], char to[], char date[],
               char seat[], char travelClass[])
{
    node *newrec, *p;
    newrec = (node*)malloc(sizeof(node));

    newrec->bookingId = l->nextId++;
    strcpy(newrec->name,        name);
    strcpy(newrec->flightNo,    flightNo);
    strcpy(newrec->from,        from);
    strcpy(newrec->to,          to);
    strcpy(newrec->date,        date);
    strcpy(newrec->seat,        seat);
    strcpy(newrec->travelClass, travelClass);
    newrec->prev = NULL;
    newrec->next = NULL;

    if(l->start == NULL)
    {
        l->start = newrec;
    }
    else
    {
        p = l->start;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next      = newrec;
        newrec->prev = p;
    }

    l->count++;
    printf("\nReservation added at end. Booking ID = %d", newrec->bookingId);
}

void deletebegin(LL *l)
{
    node *p;

    if(l->start == NULL)
    {
        printf("\nDeletion not possible. List is empty.");
    }
    else
    {
        p        = l->start;
        l->start = l->start->next;

        if(l->start != NULL)
            l->start->prev = NULL;

        printf("\nDeleted: Booking ID = %d  Name = %s", p->bookingId, p->name);
        free(p);
        l->count--;
    }
}

void deleteend(LL *l)
{
    node *p, *q;

    if(l->start == NULL)
    {
        printf("\nDeletion not possible. List is empty.");
    }
    else if(l->start->next == NULL)
    {
        p        = l->start;
        l->start = NULL;
        printf("\nDeleted: Booking ID = %d  Name = %s", p->bookingId, p->name);
        free(p);
        l->count--;
    }
    else
    {
        q = l->start;
        while(q->next->next != NULL)
        {
            q = q->next;
        }
        p       = q->next;
        q->next = NULL;
        p->prev = NULL;
        printf("\nDeleted: Booking ID = %d  Name = %s", p->bookingId, p->name);
        free(p);
        l->count--;
    }
}

void deletebyid(LL *l, int id)
{
    node *p;

    if(l->start == NULL)
    {
        printf("\nList is empty. Cannot delete.");
        return;
    }

    p = l->start;
    while(p != NULL && p->bookingId != id)
    {
        p = p->next;
    }

    if(p == NULL)
    {
        printf("\nBooking ID %d not found.", id);
        return;
    }

    if(p->prev != NULL)
        p->prev->next = p->next;
    else
        l->start = p->next;

    if(p->next != NULL)
        p->next->prev = p->prev;

    printf("\nDeleted: Booking ID = %d  Name = %s", p->bookingId, p->name);
    free(p);
    l->count--;
}

void searchbyid(LL *l, int id)
{
    node *p;
    int   found = 0;

    if(l->start == NULL)
    {
        printf("\nList is empty.");
        return;
    }

    p = l->start;
    while(p != NULL)
    {
        if(p->bookingId == id)
        {
            found = 1;
            break;
        }
        p = p->next;
    }

    if(found == 1)
    {
        printf("\n--- Reservation Found ---");
        printf("\nBooking ID   : %d",   p->bookingId);
        printf("\nPassenger    : %s",   p->name);
        printf("\nFlight No.   : %s",   p->flightNo);
        printf("\nRoute        : %s --> %s", p->from, p->to);
        printf("\nDate         : %s",   p->date);
        printf("\nSeat         : %s",   p->seat);
        printf("\nClass        : %s",   p->travelClass);
        printf("\nPrev Node    : %s",   p->prev ? "Linked" : "NULL (HEAD)");
        printf("\nNext Node    : %s",   p->next ? "Linked" : "NULL (TAIL)");
    }
    else
    {
        printf("\nBooking ID %d not found.", id);
    }
}

void searchbyname(LL *l, char name[])
{
    node *p;
    int   found = 0;

    if(l->start == NULL)
    {
        printf("\nList is empty.");
        return;
    }

    p = l->start;
    while(p != NULL)
    {
        if(strcmp(p->name, name) == 0)
        {
            found = 1;
            printf("\n--- Reservation Found ---");
            printf("\nBooking ID   : %d",   p->bookingId);
            printf("\nPassenger    : %s",   p->name);
            printf("\nFlight No.   : %s",   p->flightNo);
            printf("\nRoute        : %s --> %s", p->from, p->to);
            printf("\nDate         : %s",   p->date);
            printf("\nSeat         : %s",   p->seat);
            printf("\nClass        : %s\n", p->travelClass);
        }
        p = p->next;
    }

    if(found == 0)
        printf("\nPassenger '%s' not found.", name);
}

void display(LL *l)
{
    int   c;
    node *p;

    if(l->start == NULL)
    {
        printf("\nList is empty...");
        return;
    }

    printf("\n1-Forward Direction\n2-Backward Direction\nEnter Choice = ");
    scanf("%d", &c);

    if(c == 1)
    {
        p = l->start;
        printf("\n\nNULL <-> ");
        while(p != NULL)
        {
            printf("[ID:%d | %s | %s->%s]", p->bookingId, p->name, p->from, p->to);
            if(p->next != NULL)
                printf(" <-> ");
            p = p->next;
        }
        printf(" <-> NULL");

        printf("\n\n%-5s %-20s %-8s %-8s %-8s %-12s %-5s %-10s",
               "ID", "Passenger", "Flight", "From", "To", "Date", "Seat", "Class");
        printf("\n--------------------------------------------------------------------");
        p = l->start;
        while(p != NULL)
        {
            printf("\n%-5d %-20s %-8s %-8s %-8s %-12s %-5s %-10s",
                   p->bookingId, p->name, p->flightNo,
                   p->from, p->to, p->date,
                   p->seat, p->travelClass);
            p = p->next;
        }
    }
    else if(c == 2)
    {
        p = l->start;
        while(p->next != NULL)
        {
            p = p->next;
        }

        printf("\n\nNULL <-> ");
        while(p != NULL)
        {
            printf("[ID:%d | %s | %s->%s]", p->bookingId, p->name, p->from, p->to);
            if(p->prev != NULL)
                printf(" <-> ");
            p = p->prev;
        }
        printf(" <-> NULL");
    }
    else
    {
        printf("\nInvalid Choice...");
    }

    printf("\n\nTotal reservations = %d", l->count);
}

int main()
{
    int  ch, id;
    char name[50], flightNo[15], from[20], to[20];
    char date[15], seat[6], travelClass[10];

    LL l;
    l.start  = NULL;
    l.count  = 0;
    l.nextId = 1;

    insertend(&l, "Arjun Mehta",  "AI-202", "BOM", "DEL", "10-05-2026", "14A", "Economy");
    insertend(&l, "Priya Sharma", "6E-441", "DEL", "BLR", "11-05-2026", "22C", "Business");
    insertend(&l, "Ravi Gupta",   "SG-101", "BOM", "CCU", "12-05-2026",  "5B", "First");

    while(1)
    {
        printf("\n\nMenu:\n1-Insert at beginning\n2-Insert at end\n3-Delete at beginning\n4-Delete at end\n5-Delete by Booking ID\n6-Search by Booking ID\n7-Search by Passenger Name\n8-Display\n9-EXIT\nEnter Choice = ");
        scanf("%d", &ch);

        if(ch == 9)
            break;

        switch(ch)
        {
            case 1:
            case 2:
            {
                printf("\nEnter Passenger Name  = ");
                scanf(" %[^\n]", name);
                printf("Enter Flight Number   = ");
                scanf(" %[^\n]", flightNo);
                printf("Enter From City       = ");
                scanf(" %[^\n]", from);
                printf("Enter To City         = ");
                scanf(" %[^\n]", to);
                printf("Enter Date(DD-MM-YYYY)= ");
                scanf(" %[^\n]", date);
                printf("Enter Seat Number     = ");
                scanf(" %[^\n]", seat);
                printf("Enter Class(Economy/Business/First) = ");
                scanf(" %[^\n]", travelClass);

                if(ch == 1)
                    insertbegin(&l, name, flightNo, from, to, date, seat, travelClass);
                else
                    insertend(&l, name, flightNo, from, to, date, seat, travelClass);
            }
            break;

            case 3:
            {
                deletebegin(&l);
            }
            break;

            case 4:
            {
                deleteend(&l);
            }
            break;

            case 5:
            {
                printf("\nEnter Booking ID to delete = ");
                scanf("%d", &id);
                deletebyid(&l, id);
            }
            break;

            case 6:
            {
                printf("\nEnter Booking ID to search = ");
                scanf("%d", &id);
                searchbyid(&l, id);
            }
            break;

            case 7:
            {
                printf("\nEnter Passenger Name to search = ");
                scanf(" %[^\n]", name);
                searchbyname(&l, name);
            }
            break;

            case 8:
            {
                display(&l);
            }
            break;

            default:
            {
                printf("\nInvalid Choice...");
            }
        }
    }

    printf("\nExiting...\n");
    return 0;
}