// header file for all structs to be placed

// check to make sure file builds 
void printMakefileSuccess(void);

// randomises enemy ship spawns for the game
void randomShipSpawn(int t_x,int t_y);


// structure for the main missile 
struct Missile
{
    enum WarHead {LONG, SHORT, NUKE, BIG_MAMMA};
    bool armed;
    int x_Missile;
    int y_Missile;
};

// ships that can be destroyed by the player
struct Enemy_Ship
{
    enum Type {Big, Small, Bertha};
    int x_Ship;
    int y_Ship;
};
