namespace melodramatic{
    class matrix{
        public:
            matrix(){
                data = new float[16];
                for(int row = 0; row < 4;row++)
                    for (int col = 0; col < 4; col++)
                        data[row * 4 + col] = (row == col) ? 1.0f : 0.0f;
            };
            ~matrix(){
                delete[] data;
            };

            matrix(const matrix& mat){
                data = new float[16];
                for(int i =0;i<16;i++)
                    data[i] = mat.data[i];
            }

            matrix(matrix&& mat){
                data = mat.data;
                mat.data = nullptr;
            }

            matrix operator*( matrix &B)const{
                matrix result(0);
                for(int row = 0; row < 4;row++)
                    for (int col = 0; col < 4; col++)
                        for(int n = 0; n < 4; n++)
                            result.data[row*4 + col] += this->data[row*4 + n] * B.data[n*4 + col]; 
                return result;
            };

            matrix& operator=(matrix&& B){
                float* tmp = this->data;
                this->data = B.data;
                B.data = tmp;
                return *this;
            }
            matrix& operator=(matrix const &B){
                for(int i = 0;i< 4;i++){
                    for(int j =0; j< 4;j++)
                        this->data[i*4 + j] = B.data[i*4 + j];
                }
                return *this;
            }
            float* operator[](int i){
                return &data[i*4];
            }
            float* getData() const{
                return data;
            };

        private:
            matrix(int i){
                data = new float[16];
                for(int i = 0;i < 16; i++){
                        data[i] =  0.0f;
                }
            }
            float* data;
    };
}