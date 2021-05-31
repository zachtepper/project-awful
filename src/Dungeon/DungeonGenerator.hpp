#ifndef DungeonGenerator_hpp
#define DungeonGenerator_hpp

#include "Dungeon.hpp"

class DungeonGenerator
{
private:
    int minimumRoomSize;
    int roomID, dungeonID;
    int dungeonCount;

    Dungeon::Room *rootRoom;
    vector<Dungeon::Room*> vectorRooms;
    vector<Dungeon::Room*> corridors;
    vector<int> connections;

public:
    void initOriginRoom();

    DungeonGenerator();
    ~DungeonGenerator();

    // Functions    
    void deleteDungeon( Dungeon::Room *room );
    bool splitRoom( Dungeon::Room *room );

    bool random_split( Dungeon::Room *room );

    void generateDungeon( Dungeon::Room *room );
    void generateCorridors( Dungeon::Room *room );
    void generateCorridorBetween( Dungeon::Room *left, Dungeon::Room *right );

    void render(sf::RenderTarget& target);

};

#endif
