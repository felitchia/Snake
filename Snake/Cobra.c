/* Introdução à Programação - Projeto 2 de 2012

   Cobra!

   Programa escrito em C/C++ sobre a plataforma wxWidget.
   A plataforma wxWidget funciona em Windows, MacOS e Linux.

   Este ficheiro constitui apenas um ponto de partida para o
   seu trabalho. Todo este ficheiro pode e deve ser alterado
   à vontade, a começar por este comentário.
*/

/* IDENTIFICACAO DO JOGO E DOS AUTORES */

char jogo[] = "Cobra!";
char autores[] = "Adriana Santos(41049) | Felicia Negru(41058)";  // REFAZER
char autor1[] = "Adriana Santos (41049)";
char autor2[] = "Felicia Negru (41058)";  // REFAZER


/* INCLUDES */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "wxTiny.h"


/* UTIL */

#define MAX_STRING   256
#define MAX_LINHA    1024

typedef char String[MAX_STRING];
typedef char Linha[MAX_LINHA];


/* IMAGENS */

/* Imagens em formato XPM -- http://en.wikipedia.org/wiki/X_PixMap */

tyImage vazia_xpm = {
/* columns rows colors chars-per-pixel */
"16 16 3 1",
/* colors */
"X c Black",
"  c #6FB65D",
"A c #12971D",
/* pixels */
"                ",
"                ",
"                ",
"                ",
"      A         ",
"       A     A  ",
"        A   A   ",
"        A   A   ",
"   AA   A  A    ",
"     AA  A A    ",
"       A A      ",
"                ",
"                ",
"                ",
"                ",
"                "};

tyImage arbusto_xpm = {
/* columns rows colors chars-per-pixel */
"16 16 4 1",
/* colors */
"X c #000000",
"  c #5BB65C",
"O c Red",
"U c #488B37",
/* pixels */
"                ",
"        XX  XX  ",
"  XX   XX XX    ",
"  XX   X XXX X  ",
"  XXOOXX XX  OO ",
"   XXXX  XX  XX ",
"X   XXX XX   XX ",
" XX  XOOXX  XXX ",
" XX   X X  XXXX ",
" XXX XX XX XXOO ",
"  XXX X  X XX   ",
" X  XXXX X XXX  ",
"    XXXXXXXX    ",
" XXXXXXXXXXX    ",
"UUXXXXXXXXX     ",
" UUUUUXXXX      ",};
  

tyImage baga_azul_xpm = {
/* columns rows colors chars-per-pixel */
"16 16 8 1",
/* colors */
"X c #2E2EFE",
"  c #5BB65C",
"V c #017712",
"Z c #0B0B61",
"O c #190B07",
"Y c #08298A",
"U c #488B37",
"- c White",
"    OO   VVV    ",
"     OOVVVVVVV  ",
"     OOVVVZZZZ  ",
"  ZZZ OOVZXXXXZ ",
" ZYXXXXXXXXX-XXZ",
" ZYXXXXXXXXXXXXZ",
"ZZYXXXXXXXXXXXXZ",
"ZZYXXXXXXXXXXXXZ",
"ZZZYXXXXXXXXXXXZ",
"ZZZYXXXXXXXXXXXZ",
" ZZZYXXXXXXXXXZ ",
" ZZZYXXXXXXXXXZ ",
" UZZZZYXXXXXXZ  ",
" UUZZZZYYXXXXZ  ",
" UUUZZZZZYYZZ   ",
"  UUUUUZZZZZ    "};


tyImage baga_xpm = {
/* columns rows colors chars-per-pixel */
"16 16 8 1",
/* colors */
"X c #FF0000",
"  c #5BB65C",
"V c #017712",
"Z c #8A0808",
"O c #190B07",
"Y c #B40404",
"U c #488B37",
"- c White",
"    OO   VVV    ",
"     OOVVVVVVV  ",
"     OOVVVZZZZ  ",
"  ZZZ OOVZXXXXZ ",
" ZYXXXXXXXXX-XXZ",
" ZYXXXXXXXXXXXXZ",
"ZZYXXXXXXXXXXXXZ",
"ZZYXXXXXXXXXXXXZ",
"ZZZYXXXXXXXXXXXZ",
"ZZZYXXXXXXXXXXXZ",
" ZZZYXXXXXXXXXZ ",
" ZZZYXXXXXXXXXZ ",
" UZZZZYXXXXXXZ  ",
" UUZZZZYYXXXXZ  ",
" UUUZZZZZYYZZ   ",
"  UUUUUZZZZZ    "};



tyImage cabeca_cobra_xpm = {
/* columns rows colors chars-per-pixel */
"16 16 10 1",
 /*pixels */
"X c Black",
"- c White",
"  c #5BB65C",
"Y c #C5960B",
"N c #E9B20A",
"V c #FFC71E",
"A c #610E87",
"O c #722895",
"E c #7C319F",
"U c #488B37",
"     AAAAAAA    ",
"   AAOOOOOOAA   ",
"   AAOOEEOOAA   ",
"  AA---EE---AA  ",
"  AA---OO---AA  ",
"  AA-XXOOXX-AA  ",
"  AA-XXOOXX-AA  ",
" XNN-XXNNXX-NN  ",
"XYYNNNNNNNNNNYYX",
"XYYNNVV--VVNNYYX",
" XYYNNVVVVNNYYX ",
" XYYNNNNNNNNYYX ",
" UUXYXNNNNXNYX  ",
" UUUXYYNNNYYX   ",
"  UUUUXYYYX     ",
"    UUUXXX      "};

tyImage corpo_cobra_xpm = {
/* columns rows colors chars-per-pixel */
"16 16 9 1",
/* colors */
"  c #5BB65C",
". c Black",
"Y c #C5960B",
"X c #E9B20A",
"V c #FFC71E",
"A c #610E87",
"O c #722895",
"E c #7C319F",
"U c #488B37",

/* pixels */
"     ......     ",
"    .AAAAAA.    ",
"   .AAAYYAAA.   ",
"  .AAAAYYAAAA.  ",
" .OOOOXXXXOOOO. ",
" .OOOOXXXXOOOO. ",
".OOOOXXXXXXOOOO.",
".EEEVVVVVVVVEEE.",
".EEEVVVVVVVVEEE.",
".OOOOXXXXXXOOOO.",
"U.OOOOXXXXOOOO. ",
"U.OOOOXXXXOOOO. ",
"UU.AAAAYYAAAA.  ",
" UU.AAAYYAAA.   ",
"  UU.AAAAAA.    ",
"    U......     "};


/* XPM */
tyImage rato_xpm = {
"16 16 6 1",
"  c #5BB65C",
"O c #9D9272",
". c Black",
"B c Red",
"^ c Pink",
"X c #90885B",

" ...  ...  .... ",
".XXXX.XXX.XXXX. ",
".XX.X..XX..X.XX.",
" .X.XXOOOXX.X.. ",
"   .^XXXXX^.    ",
"    .XBBBX.     ",
"    .XXBXX.   . ",
"   .XXXXXXX.   .",
"  .XXXOOOXXX.  .",
" .X.XOOOOOX.X. .",
" .X.XXO.OXX.X. .",
" .X.XXOOOXX.X. .",
" ...XXXOXXX.... ",
"    .XXXXX...   ",
"  ..XX. .XX..   ",
".XXX..   ..XXX. "};



int vazia_img, arbusto_img, baga_img, cabeca_cobra_img, corpo_cobra_img, rato_img, baga_azul_img;

void criar_imagens(void)
{
    vazia_img = tyCreateImage(vazia_xpm);
    arbusto_img = tyCreateImage(arbusto_xpm);
    baga_img = tyCreateImage(baga_xpm);
    cabeca_cobra_img = tyCreateImage(cabeca_cobra_xpm);
    corpo_cobra_img = tyCreateImage(corpo_cobra_xpm);
    rato_img = tyCreateImage(rato_xpm);
	baga_azul_img = tyCreateImage(baga_azul_xpm);
}


/* COORDENADAS */

#define MUNDO_LARGURA   45
#define MUNDO_ALTURA    25

typedef struct {
    int x, y;
} Coord;

Coord coord(int x, int y) {
    Coord c;
    c.x = x;
    c.y = y;
    return c;
}

Coord desviar(Coord c, Coord delta) {
    return coord((c.x + delta.x + MUNDO_LARGURA) % MUNDO_LARGURA,
                  (c.y + delta.y + MUNDO_ALTURA) % MUNDO_ALTURA);
}


/* CASAS DO MUNDO */

// Tipos de casas
#define VAZIA           '.'
#define CABECA          'C'
#define CORPO           'c'
#define BAGA            'O'
#define ARBUSTO         '#'
#define RATO            'R'
#define BAGAAZUL        'A'


int qual_imagem(int tipo)
{
    switch( tipo ) {
        case VAZIA: return vazia_img;
        case CABECA: return cabeca_cobra_img;
        case CORPO: return corpo_cobra_img;
        case ARBUSTO: return arbusto_img;
        case BAGA: return baga_img;
        case RATO: return rato_img;
		case BAGAAZUL: return baga_azul_img;
        default: tyFatalError("qual_imagem: '%c'", tipo); return arbusto_img;
    }
}

#define CASA_TAMANHO_LADO       16

typedef struct {
    int tipo;     // tipo da casa
    int codigo;    // indice do ator
} Casa;


/* MUNDO BIDIMENSIONAL */

Casa mundo[MUNDO_LARGURA][MUNDO_ALTURA];

void mundo_colocar(int tipo, Coord c)
{
    mundo[c.x][c.y].tipo = tipo;
    tyDrawImage(qual_imagem(tipo),
                    c.x * CASA_TAMANHO_LADO, c.y * CASA_TAMANHO_LADO);
}

void mundo_colocar_codigo(int codigo, Coord c)
{
    mundo[c.x][c.y].codigo = codigo;
}

void mundo_apagar(Coord c)
{
    mundo_colocar(VAZIA, c);
}

Casa mundo_consultar(Coord c)
{
    return mundo[c.x][c.y];
}

bool mundo_casa_estah_livre(Coord c)
{
    return mundo_consultar(c).tipo == VAZIA;
}



void mundo_apagar_tudo(void)
{
    Coord c;
	String jogador, resp = "Novo Jogador";
    for( c.y = 0; c.y < MUNDO_ALTURA; c.y++ )
        for( c.x = 0; c.x < MUNDO_LARGURA; c.x++ )
            mundo_apagar(c);
	tyStr resposta = tyQueryDialog("New Game", "Nome do Jogador:");
	if( resposta == NULL )
		resposta = resp;
	sprintf(jogador,"              JOGADOR: %s", resposta);
	tySetStatusText(0, autores);
    tySetStatusText(1, jogador);
}


Coord mundo_procurar_casa_livre(void)
{
    Coord c;
    do {
        c.x = tyRand(MUNDO_LARGURA);
        c.y = tyRand(MUNDO_ALTURA);
    } while (mundo[c.x][c.y].tipo != VAZIA);
    return c;
}


/* ATORES */

// Cobra
#define MAX_CORPO       1000
#define PONTOS_VITORIA   300

typedef struct {
    Coord cabeca; // coordenadas da cabeça
    Coord corpo[MAX_CORPO];
    int ncorpo;
    Coord delta;    // direcao movimentacao
} Cobra;

// Bagas
#define MAX_BAGAS         30
#define BAGA_TEMPO_VIDA   15
#define BAGA_FICA_AZUL    10

typedef struct {
    Coord pos;
    int vida;
} Baga;

// Arbusto
#define MAX_ARBUSTOS 1000
typedef struct {
    Coord pos;
} Arbusto;

// Rato
typedef struct {
    Coord pos;
} Rato;

/* Vars */
Arbusto arbustos[MAX_ARBUSTOS];
Cobra cobra;
Baga bagas[MAX_BAGAS];
int nbagas;
Rato rato;
int tempo = 0;

/* Animações */
void cobra_avanca()
{
	int i;
	Coord nova_cab = desviar(cobra.cabeca, cobra.delta);
	Coord ultimo_corpo = cobra.corpo[cobra.ncorpo-1];
	mundo_apagar(ultimo_corpo);
	mundo_colocar(CABECA, nova_cab);
	Coord cabeca_anterior = cobra.cabeca;
	mundo_colocar(CORPO, cobra.cabeca);
	cobra.cabeca=nova_cab;
	for(i=cobra.ncorpo-1;i>0;i--)
		cobra.corpo[i]=cobra.corpo[i-1];
	cobra.corpo[0]=cabeca_anterior;
}



void cobra_come_baga()
{
	int w, x, y;
	Coord cabeca = cobra.cabeca;
	for(w=0 ; w<MAX_BAGAS ; w++){ 
	for(x=-1; x<=1; x++){
	for(y=-1; y<=1; y++){
		Coord baga = bagas[w].pos;		
		if(cabeca.x == baga.x+x && cabeca.y == baga.y+y){
		printf("\a");
		bagas[w].vida=0;
		cobra_avanca();}}}}
	cobra.ncorpo+=1;
}

void cobra_vitoria()
{
	tyAlertDialog("Vitória", "Parabéns! \n A cobra ganhou!");
	exit(0);
}

void cobra_derrota()
{
	tyAlertDialog("Derrota", "A cobra morreu!\n Tente novamente.");
	exit(0);
}

void cobra_come_rato()
{
	int x, y;
	Coord cabeca = cobra.cabeca;
	for(x=-1; x<=1; x++){
	for(y=-1; y<=1; y++){
		if (cabeca.x == rato.pos.x+x && cabeca.y == rato.pos.y+y){
			mundo_apagar(rato.pos);
			cobra_avanca();}}}
		cobra_vitoria();
}

bool cobra_encurralada(Coord c)
{
	c = cobra.cabeca;
	int w, v, z, k;	
	for(w=0 ; w < cobra.ncorpo ; w++){
		for(v=0 ; v < cobra.ncorpo ; v++){
			for(z=0 ; z < cobra.ncorpo ; z++){
				for(k=0 ; k < cobra.ncorpo ; k++){
					if	(cobra.cabeca.x+1==cobra.corpo[w].x && cobra.cabeca.y==cobra.corpo[w].y &&
						cobra.cabeca.x-1==cobra.corpo[v].x && cobra.cabeca.y==cobra.corpo[v].y &&
						cobra.cabeca.x==cobra.corpo[z].x && cobra.cabeca.y+1==cobra.corpo[z].y &&
						cobra.cabeca.x==cobra.corpo[k].x && cobra.cabeca.y-1==cobra.corpo[k].y)
						return true;}}}}
	return false;
}

void cobra_animacao()
{
    // REFAZER
    Coord nova_cabeca = desviar(cobra.cabeca, cobra.delta);
    if( mundo_casa_estah_livre(nova_cabeca) )
        cobra_avanca();
	else if( cobra.ncorpo == PONTOS_VITORIA )
		cobra_vitoria();
	else if( mundo_consultar(nova_cabeca).tipo == RATO)
		cobra_come_rato();
	else if( mundo_consultar(nova_cabeca).tipo == BAGA || mundo_consultar(nova_cabeca).tipo == BAGAAZUL )
		cobra_come_baga();
	else if( mundo_consultar(nova_cabeca).tipo == ARBUSTO )
		cobra_derrota();
	else if( mundo_consultar(nova_cabeca).tipo == CORPO && cobra_encurralada(cobra.cabeca))
		cobra_derrota();
}


void bagas_animacao()
{
	int w, n, tique, ciclo;
	tique = w/2;
	if( n > MAX_BAGAS ) return;
    nbagas = n;
    for (w = 0; w < MAX_BAGAS; w++){
		tempo+=w/2;
		if( tempo < BAGA_TEMPO_VIDA )
				bagas[w].vida = tempo+tique;
		else if( tempo >= BAGA_TEMPO_VIDA ){
			ciclo = (tempo)/BAGA_TEMPO_VIDA;
			bagas[w].vida = (tempo-(BAGA_TEMPO_VIDA * ciclo));
		}
		if(bagas[w].vida==0){ 
		mundo_apagar(bagas[w].pos);
        Coord c = mundo_procurar_casa_livre();
        bagas[w].pos = c;
		mundo_colocar(BAGA, c);
        mundo_colocar_codigo(w, c);
		}
		else if( bagas[w].vida == BAGA_FICA_AZUL )
			mundo_colocar(BAGAAZUL, bagas[w].pos);
}}





void rato_animacao()
{
	Coord delta; 
	int x, y, opcao_maxima=0;
	for(x=-1; x<=1; x++){
	for(y=-1; y<=1; y++){
		if(mundo_casa_estah_livre(coord(rato.pos.x+x, rato.pos.y+y))){
		int distancia =  tyDistanceCircular(cobra.cabeca.x, cobra.cabeca.y, rato.pos.x+x, rato.pos.y+y, MUNDO_LARGURA, MUNDO_ALTURA);
		if( distancia > opcao_maxima)
			opcao_maxima=distancia;
		if (opcao_maxima == distancia) delta=coord(x,y);
		}
	}
	}
	Coord nova_pos = desviar(rato.pos, delta);
	if( mundo_casa_estah_livre(nova_pos) ) {
        mundo_apagar(rato.pos);
        mundo_colocar(RATO, nova_pos);
        rato.pos = nova_pos;
    }
}



void cobra_tecla(Coord c)
{
    cobra.delta = c;
}

void animacao(void)
{
    String s;
    tempo++;
    cobra_animacao();
    rato_animacao();
    bagas_animacao();
    sprintf(s, "TEMPO = %d, PONTOS = %d", tempo, cobra.ncorpo);
    tySetStatusText(2, s);
}


/* FICHEIROS */

void carregar_linha_mapa(FILE* f, int y)
{
	Linha n;
	int x;
	if (fgets (n, MAX_LINHA, f) == NULL)
		tyFatalError("Ficheiro inválido (1)");
	for(x = 0 ; x < MUNDO_LARGURA ; x++) {
		Coord c = coord(x,y);
		mundo_colocar(n[x], c);
		//printf("%d\n",x);
		switch (n[x]){
		case BAGA: 
			mundo_colocar_codigo(nbagas, c);
			bagas[nbagas].pos = c;
			bagas[nbagas].vida = nbagas % BAGA_TEMPO_VIDA;
			nbagas++;
			break;
		case RATO:
			rato.pos = c;
			break;
		}
		}	
}

void carregar_cobra(FILE* f, int tamanho)
{
	int x, y, w;
	cobra.ncorpo=tamanho;
	fscanf(f, "%d %d", &x, &y);
	cobra.cabeca=coord(x, y);
	mundo_colocar(CABECA, cobra.cabeca);
	for( w = 0 ; w < cobra.ncorpo ; w++){
		fscanf(f, "%d %d", &x, &y);
		cobra.corpo[w] = coord(x,y);
		mundo_colocar(CORPO, cobra.corpo[w]);
	}
	cobra.delta = coord(1,0);
}


void carregar_mapa(FILE* f)
{
    int y, tamanho;
	
    mundo_apagar_tudo();    
    nbagas = 0;
    for (y = 0; y < MUNDO_ALTURA; y++)
        carregar_linha_mapa(f, y);

    if( fscanf(f, "%d %d", &tempo, &tamanho) != 2 )
        tyFatalError("Ficheiro inválido (2)");
    carregar_cobra(f, tamanho);
}

void carregar_jogo(String nome_ficheiro)
{
    FILE *f = fopen(nome_ficheiro, "r");
    if( f == NULL ) {
        tyError("Erro na abertura do ficheiro: \"%s\"", nome_ficheiro);
        return;
    }
    carregar_mapa(f); 
    fclose(f);
}

void guardar_jogo(String nome_ficheiro)
{
    FILE *f = fopen(nome_ficheiro, "w");
    if( f == NULL ) {
        tyError("Erro na criacao do ficheiro: \"%s\"", nome_ficheiro);
        return;
    }
	int x, i, y, ator;
	char linha[MUNDO_LARGURA];
	for( y = 0 ; y < MUNDO_ALTURA ; y++ ){
		for( x = 0 ; x < MUNDO_LARGURA ; x++ ){
			ator = mundo[x][y].tipo;
			if(ator == BAGAAZUL )
				ator = BAGA;
			if(ator == CABECA || ator ==CORPO )
				ator = VAZIA;
			linha[x] = ator;
		}
		linha[MUNDO_LARGURA]='\0';
		fprintf(f, "%s\n", linha);
	}
	fprintf(f,"%d %d\n", tempo, cobra.ncorpo);
	fprintf(f, "%d %d\n", cobra.cabeca.x, cobra.cabeca.y);
	for (i=0; i<cobra.ncorpo; i++)
		fprintf(f, "%d %d\n", cobra.corpo[i].x , cobra.corpo[i].y);
	
    fclose(f);
}

void mooshak(void)
{
	int x, y, ator, nr_arbustos = 0, nr_bagas = 0, nr_ratos=0;
	char linha[MUNDO_LARGURA];
	for( y = 0 ; y < MUNDO_ALTURA ; y++ ){
		for( x = 0 ; x < MUNDO_LARGURA ; x++ ){
			ator = mundo[x][y].tipo;
			if( ator == BAGA || ator == BAGAAZUL ){
				ator = BAGA;
				nr_bagas++;
			}			
			if( ator == ARBUSTO )
				nr_arbustos++;
			if( ator == RATO)
				nr_ratos++;
			linha[x] = ator;
		}
	linha[MUNDO_LARGURA]='\0';
	printf("%s\n", linha);
	}
	printf("C = 1\n");
	printf("c = %d\n", cobra.ncorpo);
	printf("R = %d\n", nr_ratos);
	printf("O = %d\n", nr_bagas);
	printf("# = %d\n", nr_arbustos);
	printf(". = %d\n", MUNDO_LARGURA * MUNDO_ALTURA-(1+nr_ratos+cobra.ncorpo+nr_bagas+nr_arbustos));
}




/* EXPERIENCIA */

/* No final esta secção pode ser apagada. */
/* Mas estude este código para conseguir fazer o programa. */

void experiencia_criar_cobra(void)
{   // Cria uma cobra de comprimento 2 numa posição fixa
    int i;
    cobra.cabeca = coord(28,10);
    cobra.ncorpo = 2;
    cobra.corpo[0] = coord(27, 10);
    cobra.corpo[1] = coord(26, 10);
    cobra.delta = coord(1,0);
    mundo_colocar(CABECA, cobra.cabeca);      
    for( i = 0; i < cobra.ncorpo; i++ )
        mundo_colocar(CORPO, cobra.corpo[i]);
}

void experiencia_criar_rato(void)
{    // Cria o rato numa posição fixa
    rato.pos = coord(30,11);
    mundo_colocar(RATO, rato.pos);      
}

void experiencia_criar_bagas(int n)
{/*    // Cria n bagas dum tipo em posições aleatórias livres
    int i;
    if( n > MAX_BAGAS ) return;
    nbagas = n;
    for (i = 0; i < n; i++) {
        Coord c = mundo_procurar_casa_livre();
        bagas[i].pos = c;
        bagas[i].vida = i % BAGA_TEMPO_VIDA;
        mundo_colocar(BAGA, c);
        mundo_colocar_codigo(i, c);
		if(tempo==15)
			mundo_apagar(bagas[i].pos);
     }
*/}

void experiencia_criar_arbustos(int n)
{    // Cria n arbustos em posições aleatórias livres
     int i;
     for (i = 0; i < n; i++) {
        Coord c = mundo_procurar_casa_livre();
        mundo_colocar(ARBUSTO, c);
     }
}

void experiencia(void)
{
    tempo = 0;
    mundo_apagar_tudo();
    experiencia_criar_cobra();
    experiencia_criar_rato();
    experiencia_criar_arbustos(20);
    experiencia_criar_bagas(20);
}


/* COMANDOS DE MENU */

void comando_about(void)
{
    tyAlertDialog("About", "%s\n\n%s\n%s", jogo, autor1, autor2);
}

void comando_open_game(void)
{
    tyStr nome_ficheiro = tyOpenDialog();
    if( nome_ficheiro != NULL )
        carregar_jogo(nome_ficheiro);
}

void comando_save_game(void)
{
    tyStr nome_ficheiro = tySaveDialog();
    if( nome_ficheiro != NULL )
        guardar_jogo(nome_ficheiro);
}

void comando_quit(void)
{
    tyAlertDialog("Quit", "Adeus.\nVolte sempre!");
    exit(0);
}


/* MAIN */

void tratar_tecla(int dx, int dy)
{
    cobra_tecla(coord(dx, dy));
}

void tratar_janela(void)
{
    Coord c;
    for( c.y = 0; c.y < MUNDO_ALTURA; c.y++ )
        for( c.x = 0; c.x < MUNDO_LARGURA; c.x++ )
            mundo_colocar(mundo[c.x][c.y].tipo, c);
}

void tratar_tempo(void)
{
    animacao();
}

void tratar_menu(String command)
{
    if( strcmp(command, "About") == 0 )
        comando_about();
    else if( strcmp(command, "Open Game") == 0 )
        comando_open_game();
    else if( strcmp(command, "Save Game") == 0 )
        comando_save_game();
    else if( strcmp(command, "Quit") == 0 )
        comando_quit();
    else
        tyFatalError("Comando desconhecido: \"%s\"", command);
}

void comecar(void)
{
    //experiencia();
    carregar_jogo("cobra_start.txt");
}

int tyMain()
{
    criar_imagens();
    tySetup(
        jogo,
        MUNDO_LARGURA * CASA_TAMANHO_LADO,
        MUNDO_ALTURA * CASA_TAMANHO_LADO,
        ":+Game"
            ":&About\tCtrl-A"
            ":-"
            ":&Open Game\tCtrl-O"
            ":&Save Game\tCtrl-S"
            ":-"
            ":&Quit\tCtrl-Q",
        tratar_tecla,
        tratar_menu,
        tratar_janela,
        tratar_tempo);
    comecar();
    mooshak();
    return 0;
}
