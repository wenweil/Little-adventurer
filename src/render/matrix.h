namespace melodramatic{
    class matrix{
        public:
            matrix(){
                data = new float*[4];
                data[0] = new float[4];
                for(int i = 0;i < 4; i++){
                    for(int j = 0;j < 4; j++)
                        data[i][j] = i == j ? 1.0f : 0.0f;
                }
            };
            ~matrix(){
                for(int i = 0; i < 4; i++)
                    delete[] data[i];
                delete[] data;
            };
            matrix operator*( matrix const &B){
                matrix result(0);
                for(int row = 0; row < 4;row++)
                    for (int col = 0; col < 4; col++)
                        for(int n = 0; n < 4; n++)
                            result.data[row][col] += this->data[row][n] * B.data[n][col]; 
                return result;
            };
            matrix& operator=(matrix const &B){
                for(int i = 0;i< 4;i++){
                    for(int j =0; j< 4;j++)
                        this->data[i][j] = B.data[i][j];
                }
                return *this;
            }
        private:
            matrix(int i){
                data = new float*[4];
                data[0] = new float[4];
                for(int i = 0;i < 4; i++){
                    for(int j = 0;j < 4; j++)
                        data[i][j] =  0.0f;
                }
            }
            float** data;
    };
}