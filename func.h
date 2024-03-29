/*
Aluno: Renato Tanaka,Johnnathan Victor Sabba
Trabalho 2 LPG
Professor: Guilherme
*/

#ifndef _TRAB2_H_
#define _TRAB2_H_
#define TAMANHO_ID 100

typedef struct
{
	int valor;
	char identificador[TAMANHO_ID];
} Variavel;

typedef struct
{
	int reg1;
	int reg2;
	char *instrucao;
} CPUInt;

typedef struct
{
	int elementos;
	Variavel *variaveis;
} RAMInt;

static char *CPUInt_instrucoes[] = {"load", "store", "add", "sub", "mul", "div", "rem", "shutdown", "restore"};

CPUInt *inicializaCPU(void);
RAMInt *inicializaRAM(void);
void destruirCPU(CPUInt *);
void destruirRAM(RAMInt *);

void declararRAMInt(RAMInt *ram, int valor, char *id);

int buscando_variavel(RAMInt *variaveis, char *elemento);

void removerRAMInt(RAMInt *ram, int valor, char *id);

void executarStoreCPUInt(CPUInt *cpu, RAMInt *ram, char *dest, char *orig);
void executarLoadCPUInt(CPUInt *cpu, RAMInt *ram, char *dest, char *orig);
void printa_registradores(CPUInt *cpu, RAMInt *ram);
void calculadora(CPUInt *cpu, char *dest, char *orig);
int savecheckpoint(CPUInt *cpu, RAMInt *ram);
void loadcheckpoint(CPUInt *cpu, RAMInt *ram);
#endif