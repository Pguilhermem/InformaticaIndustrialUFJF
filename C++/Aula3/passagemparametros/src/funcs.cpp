void passagemValor(int x) //É criada uma copia do dado com o nome "x" e é feiata a operação na copia, sem alterar a variavel do codigo principal
{
    x++; //Não altera a variavel do codigo principal
}

void passagemPonteiro(int *x) //É criado um ponteiro com o nome "x" que aponta para a o local onde a variavel do codigo principal está, sendo possivel altera a mesma
{
    (*x)++; //Altera a variavel do codigo principal
}

void passagemReferencia(int &x)//O nome "x" passa a se referir a variavel do codigo principal, todas as alterações feitas nela dentro da função alteram a mesma no codigo principal
{
    x++;//Altera a variavel do codigo principal
}

