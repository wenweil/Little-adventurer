namespace melodramatic {
    class vertex{
        public:
            vertex() : x(0),y(0),z(0){};
            vertex(float inX, float inY, float inZ):x(inX),y(inY),z(inZ){};
            ~vertex() = default;
        private:
            float x,y,z;
    };
}