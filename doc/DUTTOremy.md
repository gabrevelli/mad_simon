# Suivi des scéances:

* Scéance 1:

Tout d´abord, on a commencé à partir sur un projet où le but était de faire un affichage de led pour la vitre arrière d´une voiture 
et notre but principal était de le commercialiser, mais nous avons constaté que le coût en matière élèctronique était trop importante grâce aux recherches éffectuées.
Nous avons donc décider de changer de projet.

* Scéance 2:

Nous avons choisis comme projet le jeu presenté dans le "readme".
J´ai commencé à faire des recherches sur la façon de faire du son grâce aux speakers et ainsi j´ai decouvert la fonction tone() de l´arduino.
Gabriel et moi avons ensuite tester des leds RVB, essayer plusieurs couleurs et nous avons constater qu´il nous faudra des vitres en plexiglace pour permettre une meilleur visions des couleurs. ( https://www.carnetdumaker.net/articles/utiliser-des-leds-rgb-avec-une-carte-arduino-genuino/)

* Scéance 3:

Tout d'abord, nous avons rééssayer de faire marcher les LED RGV et j'ai ensuite changé la fonction que l'on avait créé pour pouvoir regrouper les 3 valeusr des pins d'une led en une liste de valeur. Ensuite, nous nous sommes attaqué au Speaker, nous avons reussi a faire des sons grace à ce module et même nous avons pu jouer une air de tétris. Gabriel a ensuite chercher les frequences des sons qui nous intéressent pour notre jeux tandis que moi je me suis renseigner sur l'utilisation du module permettant d'avoir plus de PWM, et je pense avoir compris comment ça marche grace au site: https://create.arduino.cc/projecthub/jithinsanal1610/servo-motor-using-arduino-pca9685-16-chanel-module-d9666e

* Scéance 4:

On a reçu les LED que l'on va utiliser finalement, j'ai donc essayé de les instaler. Petit problème, on n'a pas à disposition de cables femèle/femèle. Apres avoir reflechis à une solution, j'ai opté pour l'idée de souder deux mâle/femèle ensemble pour faire le cable qu'il nous faut. J'en ai fait donc une vingtaine pour le module PWM16. Je n'ai pas eu le temps de faire le branchement.

* Scéance intermediaire 4-5:

J'ai terminé le brancement final des LED avec le PWM16. Mais il reste à relier toutes les bases des LED et celle du PWM16 en un seul cable pour pouvoir enlever la tablette ou l'on fait tout les branchements.

* Scéance 5:

Pendant cette scéance, j'ai fait un cable pour pouvoir brancher toutes les bases des leds ensemple avec celle de l'arduino et du module PWM 16, ca fait quand meme 8 sorties pour un cable et quand j'ai essayer de brancher le tout ca ne marchais pas, je sais pas si c'est mes cables qui sont mal soudée ou le branchement que j'ai fait qui est mal fait.

* Scéance intermédiaire 5-6:

J'ai fais un patron en papier pour la "boite" finale, nous sommes ensuite allé au Fablab pour pouvoir la réaliser mais nous nous sommes rendu compte qu'il nous manquait plusieurs informations pour pouvoir les decouper en bois comme des angles et des mesures et surtout qu'il fallais arriver avec un patron sur l'ordinateur. Nous sommes donc rentré chez nous les mains vides.
Pendant les vacances de février, j'ai télécherger Autodesk et au lieu de faire les dessins en 2D et de le faire decouper sur du bois nous avons decider de le faire en 3D pour pouvoir faire une forme plus atypique et pour avoir un rendu final plus beau.
Nous avons donc ensuite fait imprimer nos deux piece et nous sommes assez satisfait du rendu final.

* Scéance 6 :

Gabriel etant malade, j'ai recuperer ce que je pensais être le programme pour pouvoir l'essayer lorsque j'aurai poser toutes les leds et tout les modules dans notre "boite". Mais quand ce que j'ai recupérer n'etait que le premier essaie de notre programme qui n'était pas addapté au module 16PWM. au lieu de retaper tous le programme ce qui m'aurai pris au mois l'heur, j'ai plutot fait l'instalations de toutes les LEDS, du module 16PWM et de l'arduino dans la "boite", ainsi que le buzzer. Maintenant il faut juste uqe je teste voir si tout marche au mieux au niveau élèctronique.
Ce qu'il reste a faire au niveau élèctronique c'est brancher deux module bluetooth pour pouvoir connecter deux portable si on veux en connecter deux et faire un mode multijoueur.* Scéance 6:

J'ai amménagé tous les composants dan la boite imprimé du fablab et j'ai enfin pu essayer les leds, toutes les leds fonctinnaient.

* Scéance 7:

J'ai commencé a branché le bluetooth, j'avais oublié qu'il nous fallais 2 resistances par LED. j'ai donc soudé les résistances et branché les cartes bluetooth à la base et au VCC.
Petit problème: j'ai fais tomber une goute d'etain sur la cate arduino. j'ai essayer de tout enlever mais helas maintenant la carte ne fonctionne plus. Nous utilisons donc actuellement la carte arduino de Gabriel.

* Scéance 8:

Notre programme ne fonctionnais pas. On a donc essayer de voir si cela venais du code ou de l'élèctronique. Il y avais quelques calbes qui n'avais pas aprécier le voyage et ils se sont desouder. j'ai donc resouder tous les cables restant et à la fin de la scéance, tout fonctinnais bien.

* Scéance 9 :

Encore une fois, le fait de transporter la "boite" a dessouder/casser quelques cables. J'ai donc ressouder ces cables et j'ai renforcer tous les cables avec du scotch pour renforcer les soudures et ainsi éviter que les soudures ne lachent.

* Scéance 10 :

Mainteannt que tous les composants ont été branché, il fallais essayer si les puces bluetooth étaient bien branché (on avais deja essayé tous les autres composants et tous marchaient sans problème). J'ai donc fait un petit programme basique pour voir si les puces etaient connectés, je l'ai testé sur la premiere (tout marchais bien), sur la deuxième (tous marchait bien). Mais lorsque l'on branchais les deux en meme temps, le programme fonctionnait que pour la deuxième puce. Nous avons trouvé l'erreur (les puces envoyaient en simultané les reponses et le programme ne gérait que la reponse de la deuxième puce).Nous pensons que ce probleme sur ce petit programme n'aura aucune importance sur notre programme du jeu car les utilisateurs ne repondent pas parfaitement en même temps.

