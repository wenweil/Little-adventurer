namespace melodramatic {
    class vertex{
        public:
            vertex() : x(0),y(0),z(0){};
            vertex(float inX, float inY, float inZ):x(inX),y(inY),z(inZ){};
            ~vertex() = default;
            void getPos(float& x, float& y, float& z){
                x = this->x;
                y = this->y;
                z = this->z;
            }
        private:
            float x,y,z;
            float r,g,b,a;
            float textureX, textureY;
            float textureID;
    };
}