#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;

struct Status{
	int nivel, vida, dano;
	string nome, ataques[2], raridade;

};

struct Item{
	int preco, unidades;
	string titulo;
};

int main() {
	Status equipe[6];
	Item bag[10];
	
	int a, e, i, j, coordM[2], coordC[2], chance = 1, fugar, lista, party = 1, opcao, cont, vidaM, vidaMax[6], captura, ataque, ataqueM;
	int derrotados, inicial, ccoins = 0, nivelA, compra, quant, coisas = 0, ganhos, uso, cura;
	char player, movimento;
	bool inCasa = false, fuga, capturado = false, bauM = false;
	string nickname;
	
	coordM[0] = 6;
	coordM[1] = 4;
	
	Status pokemon[18] = {
		{1, 35, 10, "Caterpie", {"Bug Bite", "Flock"}, "Comum"},
		{1, 30, 12, "Weedle", {"Bug Bite", "Tackle"}, "Comum"},
		{1, 45, 15, "Fletchlin", {"Extreme Speed", "Ember"}, "Comum"},
		{1, 40, 15, "Pancham", {"Tackle", "Parting Shot"}, "Comum"},
		{1, 40, 15, "Mareep", {"Eletric Wave", "Tackle"}, "Comum"},
		{1, 35, 12, "Diglett", {"Dig", "Tackle"}, "Comum"},
		{1, 60, 20, "Pikachu", {"Thunder Bolt", "Eletric ball"}, "Incomum"},
		{1, 65, 20, "Ursaring", {"Rock Smash", "Punch"}, "Incomum"},
		{1, 50, 15, "Sandile", {"Dig", "Tackle"}, "Incomum"},
		{1, 55, 20, "Riolu", {"Quick Attack", "Close Combat"}, "Incomum"},
		{1, 50, 15, "Elekid", {"Eletric Wave", "Quick Attack"}, "Incomum"},
		{1, 45, 20, "Jigglypuff", {"Pound", "Sing"}, "Incomum"},
		{1, 85, 30, "Heracross", {"Horn Atttack", "Cut"}, "Raro"},
		{1, 80, 35, "Hawlucha", {"Low Kick", "Poison Jab"}, "Raro"},
		{1, 90, 25, "Pinsir", {"Megahorn", "Cut"}, "Raro"},
		{1, 95, 30, "Beldum", {"Psychic", "Rock Polish"}, "Pseudo"},
		{1, 100, 25, "Dratini", {"Iron Tail", "Extreme Speed"}, "Pseudo"},
		{1, 999, 30, "Bidoof", {"Judgement", "Punish"}, "Lendario"},
	};
	
	Item loja[2] = {
		{10, 0, "Pokebola"},
		{15, 0, "Pocao"},
	};
	
	for(i = 0; i < 10; i++){
		bag[i].unidades = 0;
	}
	
	bag[0].titulo = "Pokebola";
	bag[0].unidades = 5;
	
	equipe[1].vida = 0;
	equipe[2].vida = 0;
	equipe[3].vida = 0;
	equipe[4].vida = 0;
	equipe[5].vida = 0;
	
	cout << "\n\tInsira o seu nickname: ";
	cin >> nickname;
	cout << "\n\tInsira o caracter desejado: ";
	cin >> player;
	system("cls");
	
	for(i = 0; i < 6; i++){
		equipe[i].nome = ".";
	}
	
	const char mapa[20][30] = {
		{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
		{'~', '_', '_', '_', '_', '_', '_', '_', '#', '#', '#', '#', '#', '#', '#', '_', '_', '_', '_', '_', '_', '_', '_', '_', 'w', 'w', 'w', 'w', 'w', '~'},
		{'~', '_', '#', '#', '#', '#', '#', '_', '#', '-', '-', '-', '-', '-', '#', '_', '_', '_', '_', '_', '_', '_', '_', '_', 'w', 'w', 'w', 'w', 'w', '~'},
		{'~', '_', '#', '-', '-', '-', '#', '_', '#', '-', '-', '-', '-', '-', '#', '_', '_', '_', '_', '_', '_', '_', '_', '_', 'w', 'w', 'w', 'w', 'w', '~'},
		{'~', '_', '#', '-', '-', '-', '#', '_', '#', '-', '-', '-', '-', '-', '#', '_', '_', '_', '_', '_', '_', '_', '_', '_', 'w', 'w', 'w', 'w', 'w', '~'},
		{'~', '_', '#', '#', '#', '#', '#', '_', '#', '#', '#', 'P', '#', '#', '#', '_', '_', '_', '_', '_', '_', '_', '_', '_', 'w', 'w', 'w', 'w', 'w', '~'},
		{'~', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', 'w', 'w', 'w', 'w', 'w', '~'},
		{'~', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', 'w', 'w', 'w', 'w', 'w', '~'},
		{'~', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', 'w', 'w', 'w', 'w', 'w', '~'},
		{'~', '_', '#', '#', '#', '#', '#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', 'w', 'w', 'w', 'w', 'w', '~'},
		{'~', '_', '#', '-', '-', '-', '#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', '~'},
		{'~', '_', '#', '-', '-', '-', '#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', '~'},
		{'~', '_', '#', '#', '#', '#', '#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', '~'},
		{'~', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '~'},
		{'~', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '~'},
		{'~', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '~'},
		{'~', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', '_', '_', '_', '_', '_', '_', '_', '_', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', '~'},
		{'~', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', '_', '_', '_', '_', '_', '_', '_', '_', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', '~'},
		{'~', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', '_', '_', '_', '_', '_', '_', '_', '_', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', '~'},
		{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
	};
	
	const char casa[8][11] = {
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', '_', '_', '_', '_', 'R', '_', '_', '_', '_', '#'},
		{'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
		{'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
		{'#', '_', '_', '_', '_', '_', '_', '_', '_', 'V', '#'},
		{'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
		{'#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#'},
		{'#', '#', '#', '#', '#', 'E', '#', '#', '#', '#', '#'},
	};
	
	system("cls");
	cout << "\n\tSeja bem-vindo ao mundo Pokemon C++, " << nickname << "!\n\tEscolha seu Pokemon inicial para comecar sua jornada:\n\t1 - Treecko\n\t2 - Swobble\n\t3 - Fuecoco\n\t---> ";
	do{
		cin >> inicial;
		switch(inicial){
			case 1: 
				equipe[0] = {5, 60, 20, "Treecko", {"Grass knot", "Bullet seed"}, "Inicial"};
				break;
			case 2:
				equipe[0] = {5, 55, 20, "Swobble", {"Bubble", "Water beam"}, "Inicial"};
				break;
			case 3:
				equipe[0] = {5, 60, 20, "Fuecoco", {"Flamethrower", "Ember"}, "Inicial"};
				break;
			default: cout << "\n\tInicial invalido! Tente novamente: ";
		}
		vidaMax[0] = equipe[0].vida;
	}while((inicial<1)||(inicial>3));
	cout << "\n\n\t\tNeste game, seu objetivo e completar uma equipe de 6 Pokemon, podendo encontra-los de forma aleatoria nos matos altos (representados pelo w) ao decorrer do mapa.\n\t";
	system("pause");
	cout << "\n\n\tO jogo conta com um dinheiro proprio chamado de C-Coins, voce pode obte-los derrotando Pokemon e utiliza-los para comprar itens na loja. Cada Pokemon tem sua classificacao de raridade, o que interfere na sua taxa de captura e tambem nos C-Coins obtidos ao derrota-los.\n\t";
	system("pause");
	cout << "\n\tO jogo tambem contem certos bugs que geralmente envolvem erros a digitacao do jogador, entao tome cuidado ao digitar em batalhas ou menus, apenas utilize numeros ou caracteres onde e adequado.\n\t";
	system("pause");
	cout << "\n\tO P do mapa representa porta para entrar no centro Pokemon, o E representa a saida, V representa o vendedor (a loja) e R o restaurador, utilize ele para curar os seus Pokemon.\n\t";
	system("pause");
	cout << "\n\t\tAlguns botoes:\n\t[E] - Ver equipe\n\t[I] - Ver Inventario\n\t";
	system("pause");
	cout << "\n\t\tBoa gameplay!\n\t";
	system("pause");
	system("cls");
	
	do{
		fuga = false;
		
   	cout << "\n\t" << nickname << " | C-Coins: " << ccoins << " | Equipe atual: " << party << " | [E], [I]\n";
    	cout << "\n\t";
    	
    	if (inCasa){
    		for (i = 0; i < 8; i++){
			   for (j = 0; j < 11; j++){
		 		   if ((i==coordC[0])&&(j==coordC[1])){
		         	cout << player << " ";
		      	}else{
	   				cout << casa[i][j] << " ";
		        }
		      }
		   	cout << "\n\t";
		   }
		}else{
	    	for (i = 0; i < 20; i++){
			   for (j = 0; j < 30; j++){
		 		   if ((i==coordM[0])&&(j==coordM[1])){
		         	cout << player << " ";
		         	if (mapa[i][j]=='w'){
		         		unsigned seed = time(0);
	          			srand (seed);
	          			chance = 1+rand() % 40;
		          		lista = 1+rand() % 18;
		         	}
		      	}else{
	   				cout << mapa[i][j] << " ";
		        }
		      }
		   	cout << "\n\t";
		   }
	   }
	   if (chance>=30){
	   	fuga = false;
	   	capturado = false;
	   	cont = 0;
	   	derrotados = 0;
	   	e = 0;
	   	nivelA = 1+rand() % 10;
	   	for (i = 0; i < 6; i++){
	   		if ((equipe[i].vida==0)&&(equipe[i].nome!=".")){
	   			e++;
	   			derrotados++;
				}else{
					i = 7;
				}
			}
	   	cout << "\n\tVoce encontrou um Pokemon!\n\t";
	   	system("pause");
	   	system("cls");
	   	if ((derrotados==party)&&(derrotados>0)){
				cout << "\n\tVoce nao tem Pokemon para usar!\n\t";
				system ("pause");
			}else{
		   	a = lista;
		   	vidaM = pokemon[a-1].vida;
		   	do{
		   		if (cont==0){
						cout << "\n\tVoce encontrou um " << pokemon[a-1].nome << " selvagem!\n";
					}
			   	cout << "\n\t| " << pokemon[a-1].nome << " | HP: " << vidaM << " | Nv. " << nivelA;
					cout << "\n\n\t\t| " << equipe[e].nome << " | HP: " << equipe[e].vida << " | Nv. " << equipe[e].nivel;
					cout << "\n\n\t" << nickname << ", o que voce deseja fazer?\n\t1 - Lutar\t2 - Inventario\n\t3 - Equipe\t4 - Fugir\n\n\t---> ";
			    	cin >> opcao;
			    	switch (opcao){
			    		case 1:
							system("cls");
							ataqueM = 1+rand() % 2;
							cout << "\n\n\t| " << equipe[e].nome << " | HP: " << equipe[e].vida << " | Nv. " << equipe[e].nivel;
							cout << "\n\n\tQual ataque " << equipe[e].nome << " deve usar?\n\t1 - " << equipe[e].ataques[0] << "\t2 - " << equipe[e].ataques[1] << "\n\n\t---> ";
	    					cin >> ataque;
	    					system("cls");
	    					cout << "\n\t" << equipe[e].nome << " usou " << equipe[e].ataques[ataque-1];
	    					vidaM -= equipe[e].dano;
	    					if (vidaM>0){
	    						ataqueM = 1+rand() % 2;
	    						if (ataqueM==1){
	    							cout << "\n\t" << pokemon[a-1].nome << " usou " << pokemon[a-1].ataques[0] << "!\n";
								}else{
									cout << "\n\t" << pokemon[a-1].nome << " usou " << pokemon[a-1].ataques[1] << "!\n";
								}equipe[e].vida -= pokemon[a-1].dano;
								if (equipe[e].vida<=0){
									cout << "\n\t" << equipe[e].nome << " foi derrotado!\n\t";
									equipe[e].vida = 0;
									system("pause");
									system("cls");
									derrotados++;
									if ((derrotados==party)&&(derrotados>0)){
										cout << "\n\tToda sua equipe foi derrotada!\n\n";
										system ("pause");
									}else{
										cout << "\n\tEscolha um novo pokemon para usar!";
										for (i = 0; i < 6; i++){
											cout << "\n\t" << i+1 << " - " << equipe[i].nome;
											if (equipe[i].nome!="."){
												cout << " | HP: " << equipe[i].vida << " | Nv. " << equipe[i].nivel;
												if (equipe[i].vida<=0){
													cout << " - DERROTADO";
												}
											}
										}
										cout << "\n\tQual pokemon voce quer usar?\n\t---> ";
										do{
											cin >> e;
											if ((e<=0)||(e>=7)){
												cout << "\n\tPokemon inexistente! Tente novamente: ";
												continue;
											}
											if (equipe[e-1].nome=="."){
												cout << "\n\tPeokemon inexistente! Tente novamente: ";
												continue;
											}
											if ((equipe[e-1].vida<=0)&&(equipe[e-1].nome!=".")){
												cout << "\n\tEsse Pokemon esta derrotado! Tente outro: ";
												continue;
											}
											break;
										}while(true);
										e--;
										system("cls");
									}
		    					}
							}else{
								system("cls");
								cout << "\n\t" << pokemon[a-1].nome << " foi derrotado!\n\t";
								if (pokemon[a-1].raridade=="Comum"){
									ganhos = 5;
									ccoins += ganhos;
								}else{
									if (pokemon[a-1].raridade=="Incomum"){
										ganhos = 7;
										ccoins += ganhos;
									}else{
										if (pokemon[a-1].raridade=="Raro"){
											ganhos = 15;
											ccoins += ganhos;
										}else{
											if (pokemon[a-1].raridade=="Pseudo"){
												ganhos = 25;
												ccoins += ganhos;
											}else{
												if (pokemon[a-1].raridade=="Lendario"){
													ganhos = 50;
													ccoins += ganhos;
												}
											}
										}
									}
								}
								cout << "\n\tVoce recebeu C$" << ganhos << " pela batalha..\n\t";
								system("pause");
								system("cls");
							}break;
						case 2:
							coisas = 0;
							for (i = 0; i < 10; i++){
								if (bag[i].unidades>0){
									coisas++;
								}
							}
							if (coisas>0){
								system("cls");
								cout << "\n\t Inventario: ";
								for (i = 0; i < 10; i++){
									if (bag[i].unidades>0){
										cout << "\n\t" << i+1 << " - " << bag[i].titulo << " x" << bag[i].unidades;
									}
								}
								cout << "\n\t[0] - Para voltar";
								cout << "\n\n\tInsira qual item voce deseja usar: ";
								do{
									cin >> uso;
									if ((uso<0)||(uso>10)){
										cout << "\n\tItem inexistente! Tente novamente: ";
										continue;
									}
									if (bag[uso-1].unidades<1){
										cout << "\n\tItem inexistente! Tente novamente: ";
										continue;
									}
									break;
								}while(true);
								switch(uso){
									case 0: system("cls");
									case 1:
										if (bag[0].unidades>0){
											if (pokemon[a-1].raridade=="Comum"){
												captura = 1+rand() % 2;
											}else{
												if (pokemon[a-1].raridade=="Incomum"){
													captura = 1+rand() % 4;
												}else{
													if (pokemon[a-1].raridade=="Raro"){
														captura = 1+rand() % 7;
													}else{
														if (pokemon[a-1].raridade=="Pseudo"){
															captura = 1+rand() % 10;
														}else{
															if (pokemon[a-1].raridade=="Lendario"){
																captura = 1+rand() % 20;
															}
														}
													}
												}
											}
											if (captura==1){
												capturado = true;
											}else{
												capturado = false;
											}
											cout << "\n\tVoce arremessou uma Pokebola e . . .";
											if (capturado){
												cout << "\n\t" << pokemon[a-1].nome << " foi capturado!\n\t";
												equipe[party].nivel = nivelA;
												equipe[party].nome = pokemon[a-1].nome;
												equipe[party].vida = pokemon[a-1].vida;
												equipe[party].ataques[0] = pokemon[a-1].ataques[0];
												equipe[party].ataques[1] = pokemon[a-1].ataques[1];
												equipe[party].dano = pokemon[a-1].dano;
												vidaMax[party] = equipe[party].vida;
												vidaM = 0;
												party++;
												system("pause");
												system ("cls");
											}else{
												cout << "\n\tA Pokebola quebrou!\n\t";
												system("pause");
												system("cls");
											}bag[0].unidades--;
										}else{
											cout << "\n\tSuas Pokebolas acabaram!\n\t";
											system("pause");
											system("cls");
										}break;
									case 2:
										system("cls");
										cout << "\n\tEquipe: \n";
										for (i = 0; i < 6; i++){
											cout << "\n\t" << i+1 << " - " << equipe[i].nome;
											if (equipe[i].nome!="."){
												cout << " | HP: " << equipe[i].vida << " | Nv. " << equipe[i].nivel;
												if (equipe[i].vida<=0){
													cout << " - DERROTADO";
												}
											}
										}
										cout << "\n\tEm qual Pokemon voce quer usar?\n\t---> ";
										do{
											cin >> cura;
											if ((cura<=0)||(cura>=7)){
												cout << "\n\tPokemon inexistente! Tente novamente: ";
												continue;
											}
											if (equipe[cura-1].nome=="."){
												cout << "\n\tPeokemon inexistente! Tente novamente: ";
												continue;
											}
											if ((equipe[cura-1].vida<=0)&&(equipe[cura-1].nome!=".")){
												cout << "\n\tEsse Pokemon esta derrotado! Tente outro: ";
												continue;
											}
											break;
										}while(true);
										equipe[cura-1].vida = vidaMax[cura-1];
										cout << "\n\t" << equipe[cura-1].nome << " restaurado!\n\t";
										system("pause");
										system("cls");
								}
							}else{
								cout << "\n\tSeu inventario esta vazio!\n\t";
								system("pause");
								system("cls");
							}
							break;
						case 3:
							system("cls");
							cout << "\n\tEquipe atual:";
							for (i = 0; i < 6; i++){
								cout << "\n\t" << i+1 << " - " << equipe[i].nome;
								if (equipe[i].nome!="."){
									cout << " | HP: " << equipe[i].vida << " | Nv. " << equipe[i].nivel;
									if (equipe[i].vida<=0){
										cout << " - DERROTADO";
									}
								}
							}
							cout << "\n\tQual pokemon voce quer usar?\n\t---> ";
							do{
								cin >> e;
								if ((e<=0)||(e>=7)){
									cout << "\n\tPokemon inexistente! Tente novamente: ";
									continue;
								}
								if (equipe[e-1].nome=="."){
									cout << "\n\tPeokemon inexistente! Tente novamente: ";
									continue;
								}
								if ((equipe[e-1].vida<=0)&&(equipe[e-1].nome!=".")){
									cout << "\n\tEsse Pokemon esta derrotado! Tente outro: ";
									continue;
								}
								break;
							}while(true);
							e--;
							system("cls");
							break;                                                      
						case 4:
							fugar = 1+rand() % 3;
							if (fugar==1){
								fuga = true;
								cout << "\n\tVoce fugiu!\n\t";
								system("pause");
							}else{
								cout << "\n\tVoce nao conseguiu fugir!\n\t";
								system("pause");
								cont++;
							}system("cls");
							break;
						default: system("cls");
					}cont++;
	    		}while(((derrotados!=party)||(derrotados==0))&&(fuga==false)&&(capturado==false)&&(vidaM>0));
	    	}
	    	system("cls");
		}else{
			cout << "\n\tUse WASD para se mover! ";
	   	movimento = _getch();
	   	if (inCasa){
	   		//Dentro da casa
		   	switch (movimento){
		    		case 'w': case 'W': coordC[0] -= 1; break;
		      	case 'a': case 'A': coordC[1] -= 1; break;
		      	case 's': case 'S': coordC[0] += 1; break;
		      	case 'd': case 'D': coordC[1] += 1; break;
		      	case 'e': case 'E':
		      		system("cls");
		      		cout << "\n\t" << nickname << " | C-Coins: " << ccoins << " | Equipe atual: " << party << " | [E], [I]";
		      		cout << "\n\n\t Equipe: ";
		      		for (i = 0; i < 6; i++){
							cout << "\n\t " << i+1 << " - " << equipe[i].nome;
							if (equipe[i].nome!="."){
								cout << " | HP: " << equipe[i].vida << " | Nv. " << equipe[i].nivel;
								if (equipe[i].vida<=0){
									cout << " - DERROTADO";
								}
							}
						}cout << "\n\n\t";
						system("pause");
						system("cls");
						break;
					case 'i': case 'I':
						system("cls");
						cout << "\n\t" << nickname << " | C-Coins: " << ccoins << " | Equipe atual: " << party << " | [E], [I]";
						cout << "\n\n\t Inventario: ";
						for (i = 0; i < 10; i++){
							if (bag[i].unidades>0){
								cout << "\n\t - " << bag[i].titulo << " x" << bag[i].unidades;
							}
						}cout << "\n\n\t";
						system("pause");
						system("cls");
						break;
				}
		   	if ((casa[coordC[0]][coordC[1]]=='~')||(casa[coordC[0]][coordC[1]]=='#')||(casa[coordC[0]][coordC[1]]=='R')||(casa[coordC[0]][coordC[1]]=='V')){
					if (casa[coordC[0]][coordC[1]]=='R'){
						for (i = 0; i < 6; i++){
							if (equipe[i].nome!="."){
								equipe[i].vida = vidaMax[i];
							}
						}
						cout << "\n\tVida da equipe restaurada!\n\t";
						system("pause");
					}
					if (casa[coordC[0]][coordC[1]]=='V'){
						do{
							system("cls");
							cout << "\n\t" << nickname << " | C-Coins: " << ccoins << " | Equipe atual: " << party << " | [E], [I]\n";
							cout << "\n\tVendedor: Bem-vindo a loja do Centro Pokemon!\n\tAqui voce pode comprar itens para lhe ajudar na sua aventura.\n";
							cout << "\n\t| 1 - Pokebola\t| C$ 10,00";
							cout << "\n\t| 2 - Pocao\t| C$ 15,00";
							cout << "\n\n\t[0] - Para sair\n\n\t---> ";
							cin >> compra;
							if (compra!=0){
								if ((compra<0)||(compra>2)){
									cout << "\n\tCompra invalida!\n\t";
									system("pause");
								}else{
									cout << "\n\tInsira quantos voce quer comprar: ";
									cin >> quant;
									if (quant<0){
										cout << "\n\tQuantidade invalida!\n\t";
										system("pause");
									}else{
										if (loja[compra-1].preco*quant>ccoins){
											cout << "\n\tC-Coins insuficiente!\n\t";
											system("pause");
										}else{
											ccoins -= loja[compra-1].preco*quant;
											bag[compra-1].titulo = loja[compra-1].titulo;
											bag[compra-1].unidades += quant;
											cout << "\n\tCompra realizada!\n\t";
											system("pause");
										}
									}
								}
							}system("cls");
						}while(compra!=0);
					}
					switch (movimento){
			    		case 'w': case 'W': coordC[0] += 1; break;
			      	case 'a': case 'A': coordC[1] += 1; break;
			      	case 's': case 'S': coordC[0] -= 1; break;
			      	case 'd': case 'D': coordC[1] -= 1; break;
			   	}
				}
				if (casa[coordC[0]][coordC[1]]=='E'){
					inCasa = false;
					coordM[0] = 6;
					coordM[1] = 12;
				}
			}else{
				//Fora da casa
				switch (movimento){
		    		case 'w': case 'W': coordM[0] -= 1; break;
		      	case 'a': case 'A': coordM[1] -= 1; break;
		      	case 's': case 'S': coordM[0] += 1; break;
		      	case 'd': case 'D': coordM[1] += 1; break;
		      	case 'e': case 'E':
		      		system("cls");
		      		cout << "\n\t" << nickname << " | C-Coins: " << ccoins << " | Equipe atual: " << party << " | [E], [I]";
		      		cout << "\n\n\t Equipe: ";
		      		for (i = 0; i < 6; i++){
							cout << "\n\t " << i+1 << " - " << equipe[i].nome;
							if (equipe[i].nome!="."){
								cout << " | HP: " << equipe[i].vida << " | Nv. " << equipe[i].nivel;
								if (equipe[i].vida<=0){
									cout << " - DERROTADO";
								}
							}
						}cout << "\n\n\t";
						system("pause");
						system("cls");
						break;
					case 'i': case 'I':
						system("cls");
						cout << "\n\t" << nickname << " | C-Coins: " << ccoins << " | Equipe atual: " << party << " | [E], [I]";
						cout << "\n\n\t Inventario: ";
						for (i = 0; i < 10; i++){
							if (bag[i].unidades>0){
								cout << "\n\t - " << bag[i].titulo << " x" << bag[i].unidades;
							}
						}cout << "\n\n\t";
						system("pause");
						system("cls");
						break;
				}
		   	if ((mapa[coordM[0]][coordM[1]]=='~')||(mapa[coordM[0]][coordM[1]]=='#')){
					switch (movimento){
			    		case 'w': case 'W': coordM[0] += 1; break;
			      	case 'a': case 'A': coordM[1] += 1; break;
			      	case 's': case 'S': coordM[0] -= 1; break;
			      	case 'd': case 'D': coordM[1] -= 1; break;
			   	}
				}
				if (mapa[coordM[0]][coordM[1]]=='P'){
					inCasa = true;
					coordC[0] = 6;
					coordC[1] = 5;
				}
			}system ("cls");
		}
 	}while(party<6);
 	system("cls");
 	cout << "\n\tCONQUISTA: | Mestre Pokemon |\n\tParabens, voce completou uma equipe pokemon, seu objetivo foi concluido\n\tAte mais! :)";
}