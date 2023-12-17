namespace Heatforge 
{
    class Tile 
    {
        public:
            Tile(int id, int x, int y)
                : id(id), x(x), y(y) {};
            int id;
            int x;
            int y;
    };
}