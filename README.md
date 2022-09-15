# Zork
 
C++ Test - Simple Zork Game Assignment

## Game
The main objective is to rescue a prisoner and get out together. You have to find his ID Card and a Key for free him.

## Input operations
There are 6 different input operations: "open", "pick", "drop", "rescue", "insert", "inventory".

### open
- All doors are available and you have to choose the direction in each room: "north", "south", "east", "west".
- GOOD: open north, open west...
- BAD: open up, open down...

### pick
- There are three pickable entities: "card", "minibag", "key".
- GOOD: pick card, pick key...
- BAD: pick prisoner.

### drop
- Same instructions as pick operation.
- If minibag is dropped, all items inside will drop too (but keeping inside the bag).

### rescue
- There is only one character to be rescued: "prisoner".

### insert
- There are two insertable entities: "card", "key". The "minibag" item is the only one which can store the other two items.
- GOOD: insert card minibag, insert key minibag.
- BAD: insert card, insert card key...

### inventory
- This operation only requires this word, "inventory", for showing all the items the player has.
- If items are inside the minibag, the operation result will specify it.

## Winning steps
- open south
- pick card
- open east
- pick minibag
- open north
- pick key
- open south
- open south
- rescue prisoner
- open north
- open north 
- open north

## Author
- Oriol Sors
- Repository: https://github.com/OriolSors/Zork
- License: MIT License
