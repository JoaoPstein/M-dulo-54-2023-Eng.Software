#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 100

struct Cliente
{
	char nome[100];
	char cpf[12];
	int tipoAtendimento;
};

void clearBuffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarAtendimento(struct Cliente atendimentos[], int *num_atendimentos)
{
	if (*num_atendimentos < MAX_CLIENTES)
	{
		struct Cliente novoCliente;

		printf("Digite o nome do cliente: ");
		scanf("%99s", novoCliente.nome); 
		clearBuffer();

		printf("Digite o CPF do cliente: ");
		scanf("%11s", novoCliente.cpf); 
		clearBuffer();

		printf("Escolha o tipo de atendimento:\n");
		printf("1 - Abertura de Conta\n");
		printf("2 - Caixa\n");
		printf("3 - Gerente Pessoa Fisica\n");
		printf("4 - Gerente Pessoa Juridica\n");
		printf("Opcao: ");
		scanf("%d", &novoCliente.tipoAtendimento);

		if (novoCliente.tipoAtendimento >= 1 && novoCliente.tipoAtendimento <= 4)
		{
			atendimentos[(*num_atendimentos)++] = novoCliente;
			printf("Atendimento cadastrado com sucesso!\n");
		}
		else
		{
			printf("Opcao invalida de tipo de atendimento.\n");
		}
	}
	else
	{
		printf("Limite maximo de atendimentos alcancado.\n");
	}
}

void listarAtendimentos(struct Cliente atendimentos[], int num_atendimentos)
{
	printf("\nLista de Atendimentos Registrados:\n");
	for (int i = 0; i < num_atendimentos; i++)
	{
		printf("Nome: %s\n", atendimentos[i].nome);
		printf("CPF: %s\n", atendimentos[i].cpf);
		printf("Tipo de Atendimento: ");
		switch (atendimentos[i].tipoAtendimento)
		{
		case 1:
			printf("Abertura de Conta\n");
			break;
		case 2:
			printf("Caixa\n");
			break;
		case 3:
			printf("Gerente Pessoa Fisica\n");
			break;
		case 4:
			printf("Gerente Pessoa Juridica\n");
			break;
		}
		printf("=========================================\n");
	}
}

void listarAtendimentoPorSetor(struct Cliente atendimentos[], int num_atendimentos, int tipo)
{
	printf("=========================================\n");
	printf("Lista de Atendimentos do Setor %d:\n", tipo);

	printf("Digite o tipo de atendimento para listar: \n");
	printf("1 - Abertura de Conta\n");
	printf("2 - Caixa\n");
	printf("3 - Gerente Pessoa Fisica\n");
	printf("4 - Gerente Pessoa Juridica\n");
	printf("Opcao: ");
	scanf("%d", &tipo);

	printf("Atendimentos no setor %d:\n", tipo);
	for (int i = 0; i < num_atendimentos; i++)
	{
		if (atendimentos[i].tipoAtendimento == tipo)
		{
			printf("Nome: %s\n", atendimentos[i].nome);
			printf("CPF: %s\n", atendimentos[i].cpf);
			printf("Tipo Atendimento: %d\n", atendimentos[i].tipoAtendimento);
			printf("=========================================\n");
		}
	}
}

int main()
{
	struct Cliente atendimentos[MAX_CLIENTES];
	int num_atendimentos = 0;
	int opcao;
	int tipo;

	do
	{
		printf("Bem-vindo ao sistema de atendimento\n");
		printf("1 - Solicitar Atendimento\n");
		printf("2 - Listar Atendimentos Registrados\n");
		printf("3 - Listar Atendimento por Setor\n");
		printf("4 - Sair\n");
		printf("Opcao: ");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
			cadastrarAtendimento(atendimentos, &num_atendimentos);
			break;
		case 2:
			listarAtendimentos(atendimentos, num_atendimentos);
			break;
		case 3:
			listarAtendimentoPorSetor(atendimentos, num_atendimentos, tipo);
			break;
		case 4:
			printf("Saindo do sistema.\n");
			break;
		default:
			printf("Opcao invalida.\n");
		}
	} while (opcao != 4);

	return 0;
}
