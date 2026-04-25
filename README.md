# Flight Ticket Reservation System

A menu-driven Flight Ticket Reservation System implemented in C using a **Doubly Linked List** as the core data structure.

Built as a Data Structures project for First Year Computer Engineering (Semester II).

## Data Structure Used
**Doubly Linked List** — each node holds passenger and flight details along with `prev` and `next` pointers, allowing traversal in both forward and backward directions.

## Features
- Insert reservation at beginning or end
- Delete reservation from beginning, end, or by Booking ID
- Search reservation by Booking ID or Passenger Name
- Display all reservations in forward (head → tail) or backward (tail → head) direction
- Auto-generated Booking IDs
- Preloaded with sample reservations for quick testing

## Files
`flight_reservation.c` - Main source file containing all logic 

## Menu Options
```
1 - Insert at beginning
2 - Insert at end
3 - Delete at beginning
4 - Delete at end
5 - Delete by Booking ID
6 - Search by Booking ID
7 - Search by Passenger Name
8 - Display
9 - EXIT
```

## Technologies
- Language: C
- Concepts: Doubly Linked List, Dynamic Memory Allocation, Pointers
