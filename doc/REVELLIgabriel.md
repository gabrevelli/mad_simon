# Suivi des Séances

### Séance 1 - 8 janvier 2018

Nous avons débattu sur notre projet initial qui était de mettre un affichage à LED à l'arrière d'une voiture avec un module qui calcule la distance entre la voiture et celle de derriere pour prévenir si la distance de sécurité n'est pas respecté.
Cependant nous avons abandonné l'idée car les module qui peuvent calculer une distance entre 10 et 100 metres sont trop chere.

### Séance 2 - 15 janvier 2018

**Nouveau Projet !!**
Nous avons trouvé un nouveau sujet qui suis le même style que le Super Simon mais avec des options supplémentaires, j'ai commencer à déssiner la boite qui contiendra l'arduino,  et j'ai aussi définis les variables qui nous seront essensseilles dans notre projet.
Nous avons testé les Led RVB car nous en aurons besoin de 6, nous avons recontré notre premier problème qui est que les leds dans la led RVB sont séparé et ne forme pas une couleur mais 3, nous avons donc décidé de mettre du plexiglass au dessus des led pour diffuser les lumières

### Séance 3 - 22 janvier 2018

Nous avons commencé à nous interresser aux modules et fonctions qu'on aurait besoin pour notre projet, nous nous sommes attardé sur les leds RGB où nous avons créé à partir d'une fonction trouvé sur internet, une fonction pour facilité l'admission de couleur aux leds.
Nous avons ensuite testé le piezo buzzer et testé des fréquences pour qui ne faisait pas mal aux oreilles (entre 200 et 1000), j'ai trouvé 6 sons qui pourait nous interresser car sur notre mad\_simon il y aura 6 couleur donc 6 sons associés à ces couleurs qui permettront de jouer a ce jeu. Il faut que les 6 sons soit tous différents pour qu"ils soient différenciable nettement.
Nous nous sommes ensuite attardé sur l'extension PWM.

### Séance 4 - 7 février 2018

Nous avons reçu les LED, Rémy était donc occupé avec ces fameuses LED pendant que je commançais le code de l'arduino, j'ai donc écrit sur feuille la forme la plus pratique que le code pouvait avoir pour me simplifier la vie quand je rajouterai des fonctions. J'ai donc choisit de faire une liste générale qui répertorie les données de chaques lED, ce qui permettra de simplifier les fonctions à venir.

### Séance 5 - 21 février 2018

J'ai fini de coder les fonctions pour afficher les lumières et le son que j'ai assemblé en cours, il y a des sons qui m'insuportait car il était trop aigüe pour l'oreille humaine (enfin la mienne). J'ai donc assemblé pendant le cours l'image et le son dans une seule fonction. J'ai aussi repensé le disign de la boite en faisant un dessin industriel de celui-ci cependant il était trop dur à réaliser sur autodesk et il y avait des soucis pour l'impression 3D (de comptabilité), Rémy s'est donc inspiré de mon croquis pour faire une boite sur autodesk pendant les vacances sans problème de compatibilité.

### Séance 6 - 21 mars 2018

J'ai bossé le code arduino du côté application bluetooth sur le téléphone (application pour le téléphone), cette application porte cependant des problème car elle manque de couleurs de boutons. Etant donné que j'étais malade je n'ai pas pu posé mes questions, j'ai regardé un peu d'autre applications mais je n'ai pas trouvé mon bonheur donc l'appli utilise 3 fois le bouton rouge pour l'instant. Je n'ai pas pu tester mon code sur l'arduino car il est aux Lucioles. Si je fini le code du bluetooth la semaine prochaine on sera dans les temps par rapport a notre diagramme de Grantt.

### Séance 7 - 28 mars 2018

L'application utilise maintenant un bouton carré et un bouton rond tout les deux gris au lieu de boutons rouge sur l'application du téléphone, celà évite de confondre les couleurs.

### Séance 8 - 5 avril 2018

J'avais presque terminé la partie **1 joueur**, il manquait juste des petites bricoles esthétique (par rapport à l'application). Ce mode de jeu est maintenant terminé, il marche très bien, le seul problème c'est les faux contacts qui font éteindre les modules Bluetooth.

### Séance 9 - 10 avril 2018

J'ai commencé à écrire le mode **2 Joueurs** que je n'ai pas testé encore sur l'arduino, à la fin de l'heure j'avais presque fini le mode **2 Joueurs** il manque plus qu'à l'essayer.

### Séance 10 - 15 avril 2018

J'ai un probleme au niveau du bluetooth, car la puce bluetooth ne reçoit pas de réponse du téléphone dans le mode **2 joueurs** ce que j'ai pris 1h à essayer de résoudre. maintenant le joueur deux peut envoyer des données mais le jeux à deux joueurs en même temps marche pas. C'est pourquoi, après quelques recherches, j'ai trouvé la fonction listen qui permet de dire a l'Arduino d'écouter que ce port série là. Malheureusement cette fonction n'a pas marché dans notre cas.

### Séance 11 - 4 mai 2018

On a bossé sur le bluetooth, on a presque résolu mon problème de la séance dernière et la puce bluetooth reçoit bien maintenant mais le problème c'est qu'il y en a qu'une seule qui reçoit sur les deux. On peut choisir le mode de jeu auquel on veut jouer avec le téléphone, les instructions sont marqués sur le moniteur de l'application.
