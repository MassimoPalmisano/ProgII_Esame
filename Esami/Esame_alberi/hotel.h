struct tipo_inf {
    int stelle;
    char nome[21];
    char luogo[21];
};

void copy(tipo_inf& dest, tipo_inf source);
void print(tipo_inf h);