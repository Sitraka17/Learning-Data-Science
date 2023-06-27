Démarrage rapide : découvrir les fondamentaux de DAX en 30 minutes
> Excel pour Microsoft 365 Excel 2021 Excel 2019 Excel 2016 Excel 2013
Ce guide de démarrage rapide s’adresse aux utilisateurs qui ne sont pas encore familiarisés avec Power Pivot dans Excel ni avec les projets de modèles tabulaires créés dans *SQL Server Data Tools*. Il est censé donner une présentation simple et rapide de la façon dont vous pouvez utiliser des expressions DAX (Data Analysis Expressions) pour résoudre un certain nombre de problèmes analytiques et de modélisation des données de base. Cette rubrique contient des informations conceptuelles, une série de tâches que vous pouvez effectuer, ainsi que quelques questions permettant de tester vos connaissances. Une fois que vous aurez étudié cette rubrique, vous devriez avoir une bonne compréhension des concepts fondamentaux les plus élémentaires du langage DAX.

Qu’est que le langage DAX ?
DAX est un ensemble de fonctions, d’opérateurs et de constantes qui peuvent être utilisés dans une formule, ou expression, afin de calculer et retourner une ou plusieurs valeurs. Plus clairement, DAX vous aide à créer de nouvelles informations à partir de données figurant déjà dans votre modèle.

Pourquoi DAX est-il si important ?
Il est facile de créer un classeur et d’y importer des données. Vous pouvez même créer des tableaux croisés dynamiques ou des graphiques croisés dynamiques qui affichent des informations importantes sans utiliser de formules DAX. Cependant, les choses se compliquent si vous devez analyser des données de ventes stratégiques concernant plusieurs catégories de produits et s’étalant sur des plages de dates différentes. Le même problème se pose si vous devez combiner des données d’inventaire importantes à partir de plusieurs tables dans différentes sources de données. Les formules DAX offrent cette possibilité, ainsi que de nombreuses autres fonctions importantes. Apprendre à créer des formules DAX efficaces vous aidera à tirer le meilleur parti de vos données. Une fois que vous avez obtenu les informations dont vous avez besoin, vous pouvez commencer à résoudre les véritables problèmes de votre entreprise qui ont une incidence sur votre chiffre d’affaires. Il s’agit d’aide à la décision et DAX vous aidera à y parvenir.

Configuration requise
Vous êtes peut-être déjà familiarisé avec la création de formules dans Microsoft Excel. Ces connaissances vous seront utiles pour comprendre le langage DAX, mais même si vous n’avez aucune expérience avec les formules Excel, les concepts décrits ici vous aideront à créer des formules DAX et à résoudre les problèmes de décisionnel réels immédiatement.

Nous allons nous concentrer spécifiquement sur les formules DAX utilisées dans les calculs. Vous devez déjà être familiarisé avec les concepts fondamentaux des colonnes et mesures calculées (également appelées champs calculés), qui sont décrits dans l’aide Power Pivot 'équipe. Vous devez également être familiarisé avec l’environnement de création et les outils Power Pivot dans Excel.

Classeur d’exemple
Le meilleur moyen de découvrir DAX est de créer des formules de base, de les utiliser avec des données réelles et de voir les résultats par vous-même. Les exemples et les tâches décrites ici font appel au classeur d’exemple DAX Formulas.xlsx de Contoso. Vous pouvez télécharger le classeur à l’adresse http://go.microsoft.com/fwlink/?LinkID=237472&clcid=0x409. Une fois que le classeur est téléchargé sur votre ordinateur, ouvrez-le, puis ouvrez la fenêtre Power Pivot.

C’est parti !
Nous allons aborder DAX autour de trois concepts fondamentaux très importants : syntaxe, fonctions et contexte. Naturellement, il existe d’autres concepts importants dans DAX, mais la compréhension de ces trois notions servira de socle sur lequel vous pourrez approfondir vos connaissances de DAX.

Syntaxe
Avant de créer vos propres formules, jetons un coup d’œil à la syntaxe des formules DAX. La syntaxe inclut les différents éléments qui composent une formule, ou plus simplement, elle correspond au mode de rédaction de la formule. Par exemple, regardons une formule DAX simple permettant de créer de nouvelles données (valeurs) pour chaque ligne d’une colonne calculée, nommée Margin, dans une table FactSales : (les couleurs du texte de formule sont fournies à titre indicatif uniquement)

Formule de colonne calculée

La syntaxe de cette formule contient les éléments suivants :

L’opérateur de signe égal (=) indique le début de la formule, laquelle, lorsqu’elle est calculée, retourne un résultat ou une valeur. Toutes les formules qui calculent une valeur commencent par un signe égal.

La colonne référencée [SalesAmount] contient les valeurs desquelles nous souhaitons effectuer une soustraction. Une référence de colonne dans une formule est toujours entourée par des crochets []. Contrairement aux formules Excel qui font référence à une cellule, une formule DAX fait toujours référence à une colonne.

Opérateur mathématique de soustraction (-).

La colonne référencée [TotalCost] contient les valeurs que nous souhaitons soustraire des valeurs de la colonne [SalesAmount].

Pour tenter de comprendre comment lire une formule DAX, il est souvent pratique de décomposer chacun des éléments afin de les reformuler dans la langue que vous utilisez tous les jours. Par exemple, vous pouvez lire cette formule comme suit :

Dans la table FactSales, pour chaque ligne de la colonne calculée Margin, calculez (=) une valeur en soustrayant (-)les valeurs de la colonne [TotalCost]des valeurs de la colonne [SalesAmount].

Examinons un autre type de formule, utilisé dans une mesure :

Formule de colonne calculée

Cette formule contient les éléments de syntaxe suivants :

Nom de la mesure Somme du montant des ventes. Les formules de mesures peuvent inclure le nom de la mesure, suivi de deux-points, puis la formule de calcul.

L’opérateur de signe égal (=) indique le début de la formule de calcul. Au moment du calcul, un résultat est retourné.

La fonction SUM additionne tous les nombres de la colonne [SalesAmount]. Vous en apprendrez plus sur les fonctions dans la suite de ce didacticiel.

Les parenthèses () délimitent un ou plusieurs arguments. Toutes les fonctions requièrent au moins un argument. Un argument transmet une valeur à une fonction.

La table référencée FactSales.

La colonne référencée [SalesAmount] de la table FactSales. Avec cet argument, la fonction SUM sait sur quelle colonne effectuer l’agrégation d’une somme.

Vous pouvez lire cette formule comme suit :

Pour la mesure nommée Somme du montant des ventes, calculez (=)la SOMME des valeurs de la colonne [SalesAmount]de la table FactSales.

Lorsqu’elle est placée dans la zone de liste de valeurs d’une liste de champs de tableau croisé dynamique, cette mesure calcule et renvoie les valeurs définies par chaque cellule du tableau croisé dynamique, par exemple, les téléphones portables aux États-Unis.

Notez quelques différences entre cette formule et la formule que nous avons utilisée pour la colonne calculée Margin. Nous avons notamment introduit une fonction, SOMME. Les fonctions sont des formules préécrites qui facilitent les calculs et manipulations complexes effectués avec des nombres, des dates, des heures, du texte, etc. Vous en apprendrez plus sur les fonctions dans la suite de ce didacticiel.

Contrairement à la colonne calculée Margin précédente, vous voyez que la colonne [SalesAmount] a été précédée de la table FactSales à laquelle appartient la colonne. On parle de nom de colonne complet car le nom de colonne est précédé du nom de table. Il n’est pas nécessaire d’inclure le nom de table dans la formule dans le cas de colonnes référencées dans la même table. Cela permet de raccourcir de longues formules qui font référence à de nombreuses colonnes et ainsi les rendre plus faciles à lire. Toutefois, il est pratique de toujours inclure le nom de la table dans vos formules de mesure, même dans la même table.

Remarque : Si le nom d’une table contient des espaces, des mots clés réservés ou des caractères non autorisés, vous devez placer le nom de la table entre guillemets simples. Vous devez également mettre entre guillemets les noms de tables si le nom contient des caractères ne figurant pas dans la plage de caractères alphanumériques ANSI, que vos paramètres régionaux prennent en charge le jeu de caractères ou non.

Il est très important que vos formules présentent la syntaxe correcte. Dans la plupart des cas, si la syntaxe est incorrecte, une erreur de syntaxe est retournée. Dans d’autres cas, la syntaxe peut être correcte, mais les valeurs retournées peuvent ne pas correspondre à vos attentes. Power Pivot (et SQL Server Data Tools) inclut IntelliSense ; il s’agit d’une fonctionnalité permettant de créer des formules syntaxiquement correctes en vous aidant à sélectionner les éléments appropriés.

Essayons de créer une formule simple. Cette tâche vous aide à mieux comprendre la syntaxe de formule, ainsi que la manière dont les fonctionnalités IntelliSense peuvent vous aider au niveau de la barre de formule.

Tâche : créer une colonne simple pour une colonne calculée
Si vous n’êtes pas déjà dans la Power Pivot, dans Excel, dans le ruban Power Pivot, cliquez sur Power Pivotfenêtre.

Dans la fenêtre Power Pivot, cliquez sur la table FactSales (onglet).

Faites défiler jusqu’à la colonne la plus à droite, puis dans l’en-tête de colonne, cliquez sur Ajouter une colonne.

Cliquez dans la barre de formule en haut de la fenêtre du générateur de modèles.

Barre de formule PowerPivot

Votre curseur apparaît maintenant dans la barre de formule. La barre de formule est l’emplacement où vous pouvez entrer une formule pour une colonne calculée ou un champ calculé.

Prenons un moment pour observer trois boutons situés à gauche de la barre de formule.

Formula bar

Lorsque le curseur est actif dans la barre de formule, ces trois boutons sont actifs. Le bouton situé à l’extrême gauche, X, correspond tout simplement à un bouton Annuler. Allez-y, cliquez dessus. Le curseur ne s’affiche plus dans la barre de formule ; par ailleurs, le bouton Annuler et le bouton de coche n’apparaissent plus. Allez-y, cliquez à nouveau dans la barre de formule. Le bouton Annuler et le bouton de coche réapparaissent maintenant. Cela signifie que vous êtes prêt pour l’écriture d’une formule.

Le bouton de coche correspond au bouton de vérification de la formule. Il n’a pas une grande utilité tant que vous n’avez pas écrit de formule. Nous y reviendrons un peu plus tard.

Cliquez sur le bouton Fx. Vous remarquez qu’une nouvelle boîte de dialogue s’affiche, à savoir la boîte de dialogue Insérer une fonction. La boîte de dialogue Insérer une fonction représente la méthode la plus facile pour commencer l’écriture d’une formule DAX. Nous ajouterons une fonction à une formule lorsque nous créons une mesure un peu plus tard, mais pour l’instant, vous n’avez pas besoin d’ajouter une fonction à votre formule de colonne calculée. Fermez donc la boîte de dialogue Insérer une fonction.

Dans la barre de formule, tapez un signe égal =, puis entrez un crochet ouvrant [. Vous verrez une petite fenêtre s’afficher avec toutes les colonnes de la table FactSales. Cela signifie que la fonctionnalité IntelliSense est active.

Les colonnes calculées étant toujours créées dans la table active, il est inutile de faire précéder le nom de la colonne par le nom de la table. Faites maintenant défiler la liste vers le bas et double-cliquez sur [SalesQuantity]. Vous pouvez également faire défiler jusqu’au nom de colonne souhaité, puis appuyer sur la touche Tab.

Le curseur est maintenant actif à droite de [SalesQuantity].

Tapez un espace, puis entrez un opérateur de soustraction - (signe moins), puis tapez un autre espace.

Maintenant, tapez un autre crochet ouvrant [. Cette fois, sélectionnez la colonne [ReturnQuantity], puis appuyez sur Entrée.

Si vous obtenez une erreur, examinez soigneusement la syntaxe. Si nécessaire, comparez-la à la formule de la colonne calculée Margin décrite précédemment.

Une fois que vous avez appuyé sur Entrée pour terminer la formule, le message de calcul en cours s’affiche dans la barre d’état au bas de la fenêtre Power Pivot. La procédure est rapide, même si vous venez de calculer de nouvelles valeurs pour plus de trois millions de lignes.

Cliquez avec le bouton droit sur l’en-tête de colonne et renommez la colonne, NetSales.

Voilà ! Vous venez de créer une formule DAX, certes simple, mais très puissante. Pour chaque ligne de la table FactSales, la formule NetSales calcule une valeur en soustrayant la valeur figurant dans la colonne [ReturnQuantity] de la valeur de la colonne [SalesQuantity]. Notez l’importance de la mention « Pour chaque ligne ». Ceci est un aperçu d’un autre concept très important dans DAX, le contexte de ligne. Vous en apprendrez plus sur le contexte de ligne dans la suite de ce didacticiel.

Lorsque vous tapez un opérateur dans une formule DAX, il est vraiment important de comprendre à quoi correspond le type de données dans les arguments que vous utilisez. Par exemple, si vous entrez la formule suivante, = 1 & 2, la valeur retournée correspond à la valeur textuelle « 12 ». Cela est dû au fait que l’opérateur « et commercial » (&) correspond à une concaténation de texte. DAX interprète cette formule de la manière suivante : calculez un résultat en prenant la valeur 1 en tant que texte et ajoutez la valeur 2 en tant que texte. Maintenant, si vous tapez = 1 + 2, DAX interprète cette formule comme suit : calculez un résultat en prenant la valeur numérique 1 et en y ajoutant la valeur numérique 2. Le résultat est évidemment « 3 », c’est-à-dire une valeur numérique. DAX calcule les valeurs résultantes en fonction de l’opérateur dans la formule, et non en fonction du type de données des colonnes utilisées dans l’argument. Les types de données dans DAX sont très importants, mais n’entrent pas dans le cadre de ce guide de démarrage rapide. Pour en savoir plus sur les types de données et les opérateurs dans les formules DAX, consultez la référence DAX (http://go.microsoft.com/fwlink/?LinkId=239769&clcid=0x409) dans la documentation en ligne.

Essayons une autre opération. Cette fois, vous allez créer une mesure en tapant la formule et en utilisant IntelliSense. Ne vous inquiétez pas si vous ne comprenez pas la formule dans son intégralité. Ici, l’important est de savoir comment créer une formule comportant plusieurs éléments en utilisant la syntaxe correcte.

Tâche : créer une formule de mesure
Dans la table FactSales, cliquez dans n’importe quelle cellule vide au sein de la Zone de calcul. Il s’agit de la zone de cellules vides juste au-dessous d’une table dans la fenêtre Power Pivot.

Zone de calcul de PowerPivot

Dans la barre de formule, tapez le nom « Previous Quarter Sales: ».

Tapez un signe égal = pour démarrer la formule de calcul.

Tapez les premières lettres, CAL, puis double-cliquez sur la fonction à utiliser. Dans cette formule, vous souhaitez utiliser la fonction CALCULATE.

Tapez une parenthèse ouvrante (pour commencer la saisie des arguments à transmettre à la fonction CALCULATE).

Notez qu’après avoir tapé la parenthèse ouvrante, IntelliSense vous présente les arguments requis pour la fonction CALCULATE. Vous en apprendrez un peu plus sur les arguments dans un instant.

Tapez les premières lettres de la table FactSales, puis dans la liste liste basse, double-cliquez sur FactSales[Ventes].

Tapez une virgule (,) pour spécifier le premier filtre, puis tapez PRE et double-cliquez sur la fonction PREVIOUSQUARTER.

Après avoir sélectionné la fonction PREVIOUSQUARTER, une autre parenthèse ouvrante apparaît, ce qui indique qu’un autre argument est requis ; cette fois, c’est pour la fonction PREVIOUSQUARTER.

Tapez les premières lettres, Dim, puis double-cliquez sur DimDate[DateKey].

Fermez à la fois l’argument passé à la fonction PREVIOUSQUARTER et celui transmis à la fonction CALCULATE en tapant deux parenthèses fermantes )).

Votre formule doit maintenant ressembler à ceci :

Previous Quarter Sales:=CALCULATE(FactSales[Sales], PREVIOUSQUARTER(DimDate[DateKey]))

Cliquez sur le bouton de vérification de la formule sur la barre de formule afin de valider la formule. Si vous obtenez une erreur, vérifiez chaque élément de la syntaxe.

Et voilà ! Vous venons de créer une mesure à l’aide de DAX, et pas une mesure facile à ce niveau. Cette formule permettra de calculer les ventes totales du trimestre précédent, selon les filtres appliqués dans un tableau croisé dynamique ou un graphique croisé dynamique.

Vous venez de découvrir plusieurs aspects importants des formules DAX. D’abord, cette formule intégrait deux fonctions. Notez que la fonction PREVIOUSQUARTER est imbrique en tant qu’argument passé à la fonction CALCULATE. Les formules DAX peuvent compter jusqu’à 64 fonctions imbriquées. Il est peu probable qu’une formule contienne un aussi grand nombre de fonctions imbriquées. En fait, il serait très difficile de créer et de déboguer une telle formule, et cette procédure serait probablement très fastidieuse.

Dans cette formule, vous avez également utilisé des filtres. Les filtres restreignent les éléments à calculer. Dans ce cas, vous avez sélectionné un filtre en tant qu’argument, qui est en réalité une autre fonction. Vous en apprendrez plus sur les filtres ultérieurement.

Enfin, vous avez utilisé la fonction CALCULATE. Il s’agit de l’une des fonctions les plus puissantes de DAX. À mesure que vous allez créer des modèles de données et des formules plus complexes, vous serez probablement amené à utiliser cette fonction à de nombreuses reprises. Une description complète de la fonction CALCULATE dépasse le cadre de ce guide de démarrage rapide, mais à mesure que vos connaissances de DAX s’étofferont, accordez une attention toute particulière à cette fonction.

Remarque : En général, pour pouvoir utiliser des fonctions Time Intelligence dans des formules DAX, vous devez spécifier une colonne de date unique à l’aide de la boîte de dialogue Marquer en tant que table de dates. Dans le classeur Samples.xlsx de formule DAX de Contoso, la colonne DateKey de la table DimDate est sélectionnée en tant que colonne de date unique.

Bonus supplémentaire
Vous vous demandez peut-être : « Quelle est la formule DAX la plus simple que je puisse créer ? » La réponse à cela est « la formule que vous n’avez pas besoin ». C’est exactement ce que vous pouvez faire en utilisant une fonction d’agrégation standard dans une mesure. Presque tous les modèles de données doivent filtrer et calculer sur des données agrégées. Par exemple, la fonction SOMME dans la mesure Somme du montant des ventes que vous avez vue précédemment sert à additioner tous les nombres d’une colonne particulière. DAX inclut également plusieurs autres fonctions qui agrègent des valeurs. Vous pouvez créer automatiquement des formules à l’aide d’agrégations standard à l’aide de la fonctionnalité Desum automatique.

Tâche de crédit supplémentaire : créer une formule de mesure à l’aide de la fonctionnalité Desum automatique
Dans la table FactSales, faites défiler jusqu’à la colonne ReturnQuantity, puis cliquez sur l’en-tête de colonne pour sélectionner la colonne dans son intégralité.

Sous l’onglet Accueil, dans le ruban, dans le groupe Calculs, cliquez sur le bouton Addition automatique.

# Somme automatique dans PowerPivot

Cliquez sur la flèche vers le bas en côté deUm automatique,puis cliquez sur Moyenne (notez les autres fonctions d’agrégation standard que vous pouvez utiliser également).

Immédiatement, une nouvelle mesure est créée avec le nom Moyenne de ReturnQuantity : suivi de la formule =AVERAGE([ReturnQuantity]).

Ce n’était pas bien compliqué, n’est-ce pas ? Bien entendu, toutes les formules que vous allez créer ne seront pas aussi simples. Cependant, grâce à la fonction de somme automatique, vous pouvez créer des formules simplement et rapidement à l’aide de calculs d’agrégation standard.

Ceci devrait vous donner une assez bonne compréhension de la syntaxe utilisée dans les formules DAX. Nous vous avons également présenté certaines fonctionnalités vraiment intéressantes, comme IntelliSense et la somme automatique, pour vous aider à créer des formules simples, rapides et précises. Bien sûr, il existe encore de nombreuses autres informations concernant la syntaxe que vous avez intérêt à connaître. Pour en savoir plus, consultez la référence DAX ou la documentation en ligne de SQL.

Test QuickQuiz sur la syntaxe
À quoi fonctionne ce bouton dans la barre de formule ?
Bouton Fonction

Par quoi un nom de colonne est-il toujours entouré dans une formule DAX ?

Comment écrire une formule pour ce qui suit : Dans la table
DimProduct,pour chaque ligne de la colonne calculée UnitMargin,calculez une valeur en soustrayant les valeurs de la colonne UnitCost des valeurs de la colonne Prix Unitaire ?

Les réponses sont fournies à la fin de cette rubrique.

Fonctions
Les fonctions sont des formules prédéfinies qui réalisent des calculs à l’aide de valeurs spécifiques, appelées arguments, indiquées dans une structure ou un ordre précis. Les arguments peuvent être d’autres fonctions, une autre formule, des références de colonnes, des chiffres, un texte, des valeurs logiques telles que TRUE ou FALSE, ou encore des constantes.

DAX inclut les catégories de fonctions suivantes : Date et heure, Information, Logique, Mathématique, Statistique, Texte et fonctions Time Intelligence. Si vous connaissez les fonctions des formules Excel, plusieurs des fonctions vous sembleront familières dans DAX ; toutefois, les formules DAX sont uniques à de nombreux égards :

Une fonction DAX fait toujours référence à une table ou une colonne complète. Si vous souhaitez utiliser certaines valeurs particulières d’une table ou colonne, vous pouvez ajouter des filtres à la formule.

Si vous devez personnaliser des calculs en fonction de chaque ligne, DAX fournit des fonctions qui vous permettent d’utiliser la valeur de ligne actuelle ou une valeur associée en tant que genre d’argument pour effectuer des calculs qui varient selon le contexte. Vous en apprendrez plus sur le contexte dans la suite de ce didacticiel.

DAX inclut de nombreuses fonctions qui retournent une table, plutôt qu’une valeur. La table n’est pas affichée, mais elle est utilisée pour fournir une entrée à d’autres fonctions. Par exemple, vous pouvez récupérer une table, puis compter les valeurs distinctes qu’elle contient, ou calculer les sommes dynamiques entre les colonnes ou les tables filtrées.

DAX intègre une grande diversité de fonctions Time Intelligence. Ces fonctions vous permettent de définir ou de sélectionner des plages de dates et d’effectuer des calculs dynamiques basés sur ces informations. Par exemple, vous pouvez comparer les sommes sur des périodes parallèles.

Parfois, il est difficile de déterminer les fonctions dont vous pourriez avoir besoin dans une formule. Power Pivot, et le générateur de modèles tabulaires dans SQL Server Data Tools, intègrent la fonctionnalité Insérer une fonction, une boîte de dialogue qui vous aide à sélectionner des fonctions par catégorie et fournit de brèves descriptions pour chacune d’elles.

Insérer une fonction

Nous allons créer une nouvelle formule qui inclut une fonction que vous allez sélectionner en utilisant la fonctionnalité Insérer une fonction :

Tâche : ajouter une fonction dans une formule à l’aide de la fonctionnalité Insérer une fonction
Dans la table FactSales, faites défiler jusqu’à la colonne la plus à droite, puis dans l’en-tête de colonne, cliquez sur Ajouter une colonne.

Dans la barre de formule, tapez un signe égal, =.

Cliquez sur le bouton Insérer une fonction. Insérer une fonction la boîte de dialogue Insérer une fonction s’ouvre.

Dans la boîte de dialogue Insérer une fonction, cliquez sur la zone de liste Sélectionner une catégorie. Par défaut, l’option Tout est sélectionnée, et toutes les fonctions de la catégorie Tout sont répertoriées ci-dessous. Le nombre de fonctions étant très important, vous souhaiterez les filtrer afin de faciliter la recherche du type de fonction que vous recherchez.

Pour cette formule, vous voulez retourner des données qui existent déjà dans une autre table. Pour ce faire, vous allez utiliser une fonction dans la catégorie Filtre. Cliquez sur la catégorie Filtre, puis dans Sélectionner une fonction,faites défiler la page vers le bas et double-cliquez sur la fonction RELATED. Cliquez sur OK pour fermer la boîte de dialogue Insérer une fonction.

Utilisez IntelliSense pour vous aider à trouver et à sélectionner la colonne DimChannel[ChannelName].

Fermez la formule, puis appuyez sur Entrée.

Une fois que vous avez appuyé sur Entrée pour terminer la formule, le message de calcul en cours s’affiche dans la barre d’état au bas de la fenêtre Power Pivot. Vous pouvez à présent constater que vous venez de créer une nouvelle colonne dans la table FactSales avec les informations de canal issues de la table DimChannel.

Renommez la colonne Channel.

Votre formule doit ressembler à ceci : =RELATED(DimChannel[ChannelName])

Vous venons de vous présenter une autre fonction très importante dans DAX, la fonction RELATED. La fonction RELATED retourne des valeurs à partir d’une autre table. Vous pouvez utiliser RELATED dans la mesure où il existe une relation entre la table dans laquelle vous travaillez actuellement et la table qui contient les valeurs que vous souhaitez obtenir. Naturellement, la fonction RELATED présente d’immenses possibilités. Dans ce cas, vous pouvez désormais inclure le canal de vente pour chaque vente réalisée dans la table FactSales. Vous pouvez maintenant masquer la table DimChannel dans la liste de champs de tableau croisé dynamique, ce qui facilite la navigation et permet d’afficher uniquement les informations les plus importantes dont vous avez vraiment besoin. À l’instar de la fonction CALCULATE décrite précédemment, la fonction RELATED est très importante et vous l’utiliserez probablement à de nombreuses reprises.

Comme vous pouvez le voir, les fonctions DAX peuvent vous aider à créer des formules très puissantes. Nous avons seulement abordé les aspects fondamentaux des fonctions. À mesure que vos connaissances DAX vont s’améliorer, vous allez être amené à créer des formules à l’aide de nombreuses fonctions différentes. L’une des meilleures façons d’en savoir plus sur toutes les fonctions DAX est la référence DAX (Data Analysis Expressions).

Test QuickQuiz sur les fonctions
À quoi une fonction fait-elle toujours référence ?

Une formule peut-elle contenir plusieurs fonctions ?

Quelle catégorie de fonctions utiliseriez-vous pour concaténer deux chaînes de texte dans une seule chaîne ?

Les réponses sont fournies à la fin de cette rubrique.

Contexte
Le contexte est l’un des concepts DAX les plus importants à maîtriser. Il existe deux types de contexte dans DAX : le contexte de ligne et le contexte de filtre. Nous allons tout d’abord nous intéresser au contexte de ligne.

Contexte de ligne
Pour des raisons de simplicité, le contexte de ligne peut être considéré comme correspondant à la ligne actuelle. Par exemple, vous vous souvenez de la colonne calculée Margin que vous avez vue précédemment lors de la leçon sur la syntaxe ? La formule =[SalesAmount] - [TotalCost] calcule une valeur dans la colonne Margin pour chaque ligne de la table. Les valeurs de chaque ligne sont calculées à partir des valeurs de deux autres colonnes, [SalesAmount] et [TotalCost] dans la même ligne. DAX peut calculer les valeurs de chaque ligne dans la colonne Margin car il existe un contexte : pour chaque ligne, les valeurs de la colonne [TotalCost] sont prises en compte et soustraites des valeurs de la colonne [SalesAmount].

Dans la cellule sélectionnée indiquée ci-dessous, la valeur 49,54 $ dans la ligne actuelle a été calculée en soustrayant la valeur 51,54 $ dans la colonne [TotalCost] de la valeur 101,08 $ dans la colonne [SalesAmount].

Contexte de ligne dans PowerPivot

Le contexte de ligne ne s’applique pas seulement aux colonnes calculées. Le contexte de ligne s’applique également chaque fois qu’une formule présente une fonction qui applique des filtres afin d’identifier une ligne unique dans une table. La fonction applique intrinsèquement un contexte de ligne pour chaque ligne de la table sur laquelle un filtrage a lieu. Ce type de contexte de ligne s’applique le plus souvent aux mesures.

Contexte de filtre
Le contexte de filtre est un peu plus difficile à comprendre que le contexte de ligne. Pour simplifier, essayez de vous représenter le contexte de filtre comme suit : un ou plusieurs filtres sont appliqués à un calcul qui détermine un résultat ou une valeur.

Le contexte de filtre ne remplace pas le contexte de ligne ; il s’applique en plus du contexte de ligne. Par exemple, pour restreindre les valeurs à inclure dans un calcul, vous pouvez appliquer un contexte de filtre qui spécifie non seulement le contexte de ligne, mais indique également une valeur particulière (filtre) dans ce contexte de ligne.

Le contexte de filtre est facilement observable dans des tableaux croisés dynamiques. Par exemple, lorsque vous ajoutez TotalCost à la zone Valeurs, puis ajoutez une année et une région à la ligne ou aux colonnes, vous définissez un contexte de filtre qui sélectionne un sous-ensemble de données par rapport à une année et à une région données.

Pourquoi le contexte de filtre est-il si important dans DAX ? Étant donné que si le contexte de filtre peut être appliqué très facilement en ajoutant des étiquettes de colonne et de ligne et des secteurs dans un tableau croisé dynamique, un contexte de filtre peut également être appliqué dans une formule DAX en définissant un filtre à l’aide de fonctions telles que ALL, RELATED, FILTER, CALCULATE, par des relations et par d’autres mesures et colonnes. Par exemple, examinons la formule suivante dans une mesure nommée StoreSales :

Formule

Visiblement, cette formule est plus complexe que certaines des autres formules que vous avez déjà vues. Toutefois, pour mieux comprendre cette formule, nous pouvons la décomposer, comme nous l’avons fait avec d’autres formules.

Cette formule contient les éléments de syntaxe suivants :

Nom de la mesure StoreSales, suivi de deux-points :.

L’opérateur de signe égal (=) indique le début de la formule.

La fonction CALCULATE évalue une expression, en tant qu’argument, dans un contexte modifié par les filtres spécifiés.

Les parenthèses () délimitent un ou plusieurs arguments.

Une mesure [Ventes] dans la même table qu’une expression. La mesure Sales contient la formule : =SUM(FactSales[SalesAmount]).

Une virgule (,) sépare chaque filtre.

La colonne référencée et une valeur particulière DimChannel[ChannelName] =« Store », comme filtre.

Cette formule permet de s’assurer que seules les valeurs de ventes définies par la mesure Ventes, en tant que filtre, sont calculées uniquement pour les lignes de la colonne DimChannel[ChannelName] avec la valeur « Store », comme filtre.

Comme vous pouvez l’imaginer, le fait de pouvoir définir un contexte de filtre dans une formule représente une fonction majeure et puissante. Pouvoir faire référence à une valeur particulière uniquement dans une table associée ne constitue qu’un exemple de ce type. Ne vous inquiétez pas si vous ne comprenez pas encore tous les tenants et aboutissants du contexte. À mesure que vous créerez vos propres formules, vous comprendrez mieux le contexte et son importance dans DAX.

Test QuickQuiz sur le contexte
Quels sont les deux types de contexte ?

Qu’est-ce que le contexte de filtre ?

Qu’est-ce que le contexte de ligne ?

Les réponses sont fournies à la fin de cette rubrique.

Résumé
Maintenant que vous avez une compréhension de base des concepts les plus importants dans DAX, vous pouvez commencer à créer des formules DAX pour les colonnes calculées et les mesures vous-même. Le langage DAX peut se révéler un peu compliqué à maîtriser, mais vous disposez de nombreuses ressources pour y parvenir. Une fois que vous aurez lu cette rubrique plusieurs fois et que vous aurez fait quelques expérimentations avec vos propres formules, vous pourrez approfondir vos connaissances des concepts et des formules DAX afin de pouvoir résoudre les problèmes spécifiques à votre entreprise. Il existe de nombreuses ressources DAX à votre disposition dans l’aide de Power Pivot, la Documentation en ligne de SQL Server, les livres blancs, ainsi que les blogs rédigés à la fois par Microsoft et des professionnels du secteur décisionnel. Le centre de ressources Wiki DAX (http://social.technet.microsoft.com/wiki/contents/articles/dax-resource-center.aspx) est l’endroit idéal où commencer. La référence DAX (Data Analysis Expressions) constitue également une ressource très utile. Pensez à l’enregistrer dans vos favoris.

Le livre blanc consacré à DAX dans le modèle tabulaire BI et accessible par téléchargement (http://go.microsoft.com/fwlink/?LinkID=237472&clcid=0x409) fournit une description plus détaillée des concepts présentés ici, ainsi que de nombreux autres formules et concepts avancés. Ce livre blanc utilise également le même classeur d’exemple DAX Formulas.xlsx de Contoso que vous possédez déjà.

Réponses aux tests QuickQuiz
Syntaxe :

Ouvre la fonctionnalité Insérer une fonction.

Crochets [].

=[UnitPrice] - [UnitCost]

Fonctions :

Une table et une colonne.

Oui. Une formule peut compter jusqu’à 64 fonctions imbriquées.

Fonctions de texte.

Contexte :

Contexte de ligne et contexte de filtre.

Un ou plusieurs filtres dans un calcul qui détermine une valeur unique.

La ligne actuelle.


source: https://support.microsoft.com/fr-fr/office/d%C3%A9marrage-rapide-d%C3%A9couvrir-les-fondamentaux-de-dax-en-30-minutes-51744643-c2a5-436a-bdf6-c895762bec1a
