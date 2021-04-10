typedef struct aluno Aluno;

typedef struct alunos Alunos;

Aluno *aluno_Aloca();

Aluno **aluno_AlocaVetor(int n);

Aluno ***aluno_AlocaMatriz(int t);

int aluno_getMatricula(Aluno *aluno);

double aluno_getProva(Aluno *aluno);

double aluno_getTrabPratico(Aluno *aluno);

double aluno_getMedia(Aluno *aluno);

void aluno_setMatricula(Aluno *aluno, int n);

void aluno_setProva(Aluno *aluno, double n);

void aluno_setTrabPratico(Aluno *aluno, double n);

void aluno_setMedia(Aluno *aluno, double n);

double aluno_CalculaMedia(Aluno *aluno, double pesoProva, double pesoTPratico);

void aluno_Libera(Aluno ***aluno, int n);