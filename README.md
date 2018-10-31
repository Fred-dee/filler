# filler
Work done for the Algorithm Module at WeThinkCode_

This project uses work from the <a href = "https://www.github.com/Fred-Dee/get_next_line/"> get_next_line </a> project
as well as the <a href = "https://www.github.com/Fred-Dee/libft/"> libft </a> project/

The aim of the project is to create a "player"/bot that will play against another bot in a game where capturing the most board space is the goal

<h1>Compilation And Execution</h1>
In order to compile the player I've created run Make or Make re command in the root directory
to run the game use the command (from root):
./resources/filler_vm  -f ./resources/maps/map0* -p1 'player location' -p2 ./resources/players/*
<sub>* - select a player/map from that directory. One needs ruby installed on their system to run this project</sub>

<h1>The Algorithm</h1>
The algorithm my player uses is one based on a heuristic, with some extra effort it can be trained.
The bot does a series of comparisons, taking into account the space above, below and to each side of the
relatively closest piece of mine with the board or opposition player. Then a series of weights (the trainable aspect)
determine which move should be made.
<sub>For the purposes of this specific run, the weights were manually adapted through a series of trial and error</sub>

