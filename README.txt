Este é um programa que armazena filmes em um catálogo com permanência de arquivos.

Para compilar o programa basta executar o comando make no diretório contendo todos os arquivos do projeto que irá gerar um executável chamado mainProgram.

Após o uso e saída sem erros (utilizando a opção "0" do menu principal) o catálogo é salvo no arquivo "catalogo.txt". 

Ao iniciar o programa, ele automaticamente recupera os dados salvos no arquivo de texto e instancia seu catálogo com eles. Caso queira testar o programa sem estes dados, delete o arquivo ou mude seu nome.

Todos os comandos necessários para a utilização do programa são explicitados no menu principal que se abre imediatamente após a rotina de inicialização do programa.

OBS: O programa nao suporta nomes de filmes ou de produtoras que contenham espaços. Ele entra em loop infinito, não consegui fazer com que a função getline() ignorasse " " como delimitador.

