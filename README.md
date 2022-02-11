# EDcare
Projeto de um Sistema simplificado de controle de saúde de Idosos utilizando TADs (Tipos Abstratos de Dados) em C.

\n Pula?

Arquivos de Entrada:
1. Apoio.txt: Define os Idosos Cadastrados e a relação de amizade entre eles.
2. Cuidadores.txt: Define o nome e quantidade dos cuidadores e a relação de idosos que são atendidos por quais cuidadores.

1ª e 2ª Etapas: Setup!
-----------------------------------
  1ª Etapa: Ler arquivo "apoio.txt"
    -> Ler a primeira linha que contém os idosos e armazenar cada um dos idosos na lista de idosos.
    -> Ler as próximas linhas: Cada linha define as relações de amizades.
        - Acrescenta Amigos da lista de amigos do Idoso.
  
  2ª Etapa: Ler Arquivo "cuidadores.txt"
    -> Ler a 1ª linha e armazenar todos os cuidadores na lista de cuidadores cadastrados.
    -> Ler próximas linhas>
        - Para cada linha, armazenar os cuidadores para cada um dos Idosos.

------------------------------------

TADs principais:

------------------------------------
         _______________________________
  Idoso:| - String Nome
        | - Lista de Pessoas (Amigos)
        | - Lista de Pessoas (Cuidadores)
        | - int Latitude
        | - int Longitude
        | - float temperatura
        | - Boolean Queda
        _________________________________
        
              ______________________________
  Cuidadores:| - String Nome
             | - int Latitude
             | - int Longitude
             _______________________________


Amigos são Idosos

        Pessoas
          - Idosos
          - Cuidadores








