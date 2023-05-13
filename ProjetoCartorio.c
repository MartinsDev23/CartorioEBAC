#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string


int registro() //função responsável por cadastrar os usuários no sistema
{
    //inicio criação de variaveis/string de registro

    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
    scanf("%s", cpf);//%s refere-se a string

    strcpy(arquivo, cpf); //responsável por copiar os valores das string

    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo
    fprintf(file,cpf); //salvo o valor da varíavel
    fclose(file); //fecha o arquivo

    file = fopen(arquivo, "a");//atualizando o arquivo
    fprintf(file, ",");//adicionando a Vírgula ao arquivo
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");//registrando o nome do usuário
    scanf("%s",nome);//%s refere-se a string

    file = fopen(arquivo, "a");//abrindo o arquivo e atualizando
    fprintf(file,nome);//adicionando a string nome no arquivo(file)
    fclose(file);//fechando o arquivo

    file = fopen(arquivo, "a");//atualizando o arquivo
    fprintf(file, ",");//adicionando a Vírgula ao arquivo
    fclose(file);

    printf("Digite o sobrenome a ser cadsatrado: ");//inserindo o sobrenome(string) do usuário
    scanf("%s",sobrenome);//%s refere-se a string "sobrenome"

    file = fopen(arquivo, "a");//abrindo o arquivo e atualizando
    fprintf(file,sobrenome);//adicionando a string sobrenome
    fclose(file);

    file = fopen(arquivo, "a");//abrindo o arquivo e atualizando
    fprintf(file, ",");//adicionando a vírgula
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");//inserindo a string cargo do usuário
    scanf("%s",cargo);//%s refere-se a string cargo

    file = fopen(arquivo, "a");//abrindo o arquivo e atualizando
    fprintf(file,cargo);//adicionando a string cargo no arquivo
    fclose(file);
    //Fim das variaveis/string de registro

}


int consulta()
{
    //inicio das variaveis/string de consulta

    setlocale(LC_ALL,"pt_BR_utf8");// setando a linguagem

    char cpf[40];//string do tipo caractere//definindo a string e o valor
    char conteudo[200];//string do tipo caractere//definindo a string e o valor


    printf("Digite o CPF a ser consultado: ");//coletando os dados
    scanf("%s",cpf);

    system("clear");//limpando a tela

    FILE *file;// acessando o arquivo(*file) dentro do campo FILE
    file = fopen(cpf,"r");//abrindo o file e lendo("r") a string(cpf)


    if(file == NULL)//definindo que "Se o file(arquivo armazenado for igual á NULO)
    {
        printf("Não foi possivel abrir o arquivo, não localizado!.\n");
        printf("Pressione Enter para continuar");
        getchar();
        getchar();
        return 0;
    }

    while(fgets(conteudo,200 ,file) != NULL)//Enquanto, acessando o "conteudo" dentro do "file" != sendo diferente de nulo
    {
        system("clear");
        printf("\nEssas são as informações do usuário: ");
        printf("%s",conteudo);//%s refere-se a string conteudo
        printf("\n\n");
    }

    fclose(file);//fechando o file

    printf("Pressione Enter para voltar ao menu");
    getchar();
    getchar();
    return 0;
    //fim das variaveis/string de consulta



}


int deletar()
{
    //inicio da variavel/string para deletar

    char cpf[40];

    printf("Digite o CPF do usuário que deseja deletar:");//coletando a informação
    scanf("%s",cpf);

    FILE *file;//acessando o file dentro do campo FILE(arquivo)
    file = fopen(cpf, "r");//abrindo o file e lendo("r") a string cpf

    if(file == NULL)// definindo uma condição//Se essa condição for falsa(instruções)
    {
      printf("Usuário não encontrado no sistema.\n");
      printf("Pressione Enter para voltar ao menu.\n");
      getchar();
      getchar();
    }

    else //definindo uma condição, se essa condição for verdadeira(insrtuções)
    {
        remove(cpf);
        printf("Usuário deletado com sucesso.\n\n");
        printf("Pressione Enter para voltar ao menu.\n");
        getchar();
        getchar();
        return 0;
        //Fim das variaveis/string de deletar
    }

}


int main()
{
    int opcao;//variavel %d
    int laco = 1;//laço de repetição

    while (laco == 1)//laco de repetição
    {
        setlocale(LC_ALL,"pt_BR_utf8");//Definindo a linguagem

        printf("\t### Cartório da EBAC ###\n\n");// Inicio do menu
        printf("Selecione a opção de menu desejada \n\n");
        printf("\t1- REGISTRAR NOMES \n");
        printf("\t2- CONSULTAR NOMES \n");
        printf("\t3- DELETAR NOMES \n\n");
        printf("Opcao: ");  //Fim do menu

        scanf("%d", &opcao); //Armazenando a escolha do usuario

        system("clear");

        switch (opcao)//inicio da seleção do menu
        {
            case 1://primeira seleção
            registro();//chamada de funções
            break;//fechando a primeira seleção

            case 2://segunda seleção
            consulta();//chamada de funções
            break;//fechando a segunda seleção

            case 3://terceira seleção
            deletar();//chamada de funções
            break;//fechando a terceira seleção

            default://definindo uma condição diferente das seleções

                printf("Essa opcao nao está disponível\n\n");
                printf("Pressione enter para voltar ao menu...");
                getchar(); //Aguarda a tecla enter ser pressionada
                getchar(); //Aguarda a tecla enter ser pressionada novamente
                break;
         }

        system("clear");//limpando a tela
    }

    return 0;
}


