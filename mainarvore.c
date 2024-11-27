int main (void)
/*A função main do código apresentado é responsável por executar uma série de etapas para manipular um arquivo de texto e construir uma lista ligada e uma árvore de Huffman.*/
{
	FILE *pArq;			// lista que armazenará caracteres do arquivo variavel de ponteiro dearquivo
	stLst lst;   		// declara uma lista não inicializada
	char alf;
	lst.n = 0;   		// cria e inicializa lista como vazia, e inicia em zero
	lst.first = NULL;  	// nulo, Ponteiro para o primeiro nó da lista, iniciado como NULL

	pArq = fopen("textoProg2lista.txt","r"); //fopen funcao para abrir o arquivo no modo de leitura r
	if(!pArq){  //se pArq for NULL
		printf("\n arquivo en referenica com problema...");
		exit(1);
	}

	while(!feof(pArq)) {  //O operador ! nega o valor retornado por feof, o FEOF é uma função que verifica se atingimos o final do arquivo, enquanto tiver dados dar 0, entao quando for 1 o loop para 
		fscanf(pArq, "%c ", &alf); printf("%c", alf); //A função fscanf() lê dados da posição e guarda na variavel ALF
		insereLista(&lst, alf); //adiciona o caracter na lista, se o caracter ja existir a frequencia vai ser adicionada, caso nao exista vai ser criado um novo no
	}
	fclose(pArq);

    printf("\nlista antes da ordenacao: ");
	mostraLista(&lst);

	ordenaLista(&lst);

	criaArvore(&lst); //Pega os dois primeiros elementos com menor frequência, cria um novo no que combina esses elementos, repete o processo ate que fique somente um no na lista(a raiz)

	printf("\nLista depois de ordenar: ");
	mostraLista(&lst);

	eliminaLista(&lst);

	return 0;