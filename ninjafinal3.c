/* Andreas Hinsch
   COP3223C(91735)- Intro to programming with C
   Section number: 0R06
   Assignment #8: Ninja final
   11/29/18
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ninja {
     // The search ability of the ninja
	int search;
    //Used to identify what ninja is going into the temple
    int identifier;
    //The stealth ability of the ninja
	int stealth;

};

struct map {
    //The ninja's search skill needed to search a room
    int searchval;
    // Determines what item it is
	int item;
	//Determines if a relic is found or not
	int found;
};

// Used to print out a map after each ninja goes into the temple
void map_maker(int temple_searched[3][3]);
//Fills in the array filled_map and the array filled_ninjas
void fill_in_arrays(int filled_map[18], int filled_ninjas[8]);
int main() {

//creates structs for all the possible items that can be found
   struct map trap;
   struct map katana;
   struct map scroll;
   struct map jade;
   struct map mask;
   struct map nothing;


// Creates structs for all the ninjas
   struct ninja one;
   struct ninja two;
   struct ninja three;
   struct ninja four;

//Assigns a variable to each struct that corresponds with the variable on the map used to find it
   trap.item = 0;
   katana.item = 1;
   scroll.item = 2;
   jade.item = 3;
   mask.item = 4;
   nothing.item = 5;


//Initializes all the items to be 0 or "not found"
   katana.found = 0;
   scroll.found = 0;
   jade.found = 0;
   mask.found = 0;

//How many hours the ninjas have left I used 2 because it made more sense instructions unclear
//"Your program will simulate the six hours available for this exercise"
//"Your job is to retrieve each of these relics in under two hours"
    int hours = 2;


//Map stats
    int filled_map[18];

//Ninja stats
    int filled_ninjas[8];


//What is in each part of the temple
    int temple[3][3];
//The search value needed to search each part of the temple
    int temple_search[3][3];
//What the user knows about what is in the temple initializes to 6 because it was a number outside of the 0-5 range that is reserved by the items
    int temple_searched[3][3] = {6,6,6,6,6,6,6,6,6};

//Used as a control variable
    int control = 0;

//Used to determine what ninja is going into the temple
    int ninjanum = 1;

//Used to locate where the ninja is being sent
    int ninjalocater = 0;
    int ninjalocatec = 0;

//A random variable used to determine if a ninja gets caught
    int instructor = 0;

//Used to end a ninja's turn if it is caught by an instructor
    int controls = 0;

//Counts the number of relics collected
    int Relics_collected = 0;


fill_in_arrays(filled_map, filled_ninjas);




//Fills in the temple map
for(int x = 0; x < 3; x++){
for(int y = 0; y < 3; y++){
if(filled_map[control + 1] == trap.item){trap.searchval = filled_map[control];
temple[x][y] = 0;
temple_search[x][y] = filled_map[control];
                                        }


if(filled_map[control + 1] == katana.item){katana.searchval = filled_map[control];
temple[x][y] = 1;
temple_search[x][y] = filled_map[control];
                                          }


if(filled_map[control + 1] == scroll.item){scroll.searchval = filled_map[control];
temple[x][y] = 2;
temple_search[x][y] = filled_map[control];
                                          }


if(filled_map[control + 1] == jade.item){jade.searchval = filled_map[control];
temple[x][y] = 3;
temple_search[x][y] = filled_map[control];
                                        }


if(filled_map[control + 1] == mask.item){mask.searchval = filled_map[control];
temple[x][y] = 4;
temple_search[x][y] = filled_map[control];
                                        }


if(filled_map[control + 1] == nothing.item){nothing.searchval = filled_map[control];
temple[x][y] = 5;
temple_search[x][y] = filled_map[control];
                                           }


control += 2;
}
}



//Fills in the skills for all the ninjas
    one.search = filled_ninjas[0];
    one.stealth = filled_ninjas[1];
    two.search = filled_ninjas[2];
    two.stealth = filled_ninjas[3];
    three.search = filled_ninjas[4];
    three.stealth = filled_ninjas[5];
    four.search = filled_ninjas[6];
    four.stealth = filled_ninjas[7];




//Sends in ninjas into the temple until all relics are collected or time is up
do{
map_maker(temple_searched);




//Input will be read as row, column so if you want to send a ninja to the first column in the first row type 0 press enter then type 0
printf("What row do you want to deploy ninja %d? you have %d hours remaining. \n", ninjanum,  hours);
scanf("%d", &ninjalocater);

printf("What column do you want to deploy ninja %d?\n", ninjanum);

scanf("%d", &ninjalocatec);

if(ninjanum == 1){

        srand(time(NULL));
instructor = rand()% (one.stealth + 1);


if(instructor == 0){
    printf("Your ninja has been caught!\n");
    controls = 1;
}

if(temple_search[ninjalocater][ninjalocatec] <= one.search && controls != 1){
if(temple[ninjalocater][ninjalocatec] == 0){
    printf("you have discovered a trap\n");
    one.stealth--;
    temple_searched[ninjalocater][ninjalocatec] = 0;
}

if(temple[ninjalocater][ninjalocatec] == 1){
    printf("you have discovered the katana\n");
    katana.found = 1;
    temple_searched[ninjalocater][ninjalocatec] = 1;
}
if(temple[ninjalocater][ninjalocatec] == 2){
    printf("you have discovered the scroll\n");
    scroll.found = 1;
    temple_searched[ninjalocater][ninjalocatec] = 2;
}
if(temple[ninjalocater][ninjalocatec] == 3){
    printf("you have discovered the Jade\n");
    jade.found = 1;
    temple_searched[ninjalocater][ninjalocatec] = 3;
}
if(temple[ninjalocater][ninjalocatec] == 4){
    printf("you have discovered the mask\n");
    mask.found = 1;
    temple_searched[ninjalocater][ninjalocatec] = 4;
}
if(temple[ninjalocater][ninjalocatec] == 5){
    printf("you have discovered nothing\n");
    temple_searched[ninjalocater][ninjalocatec] = 5;
}

                                              }
 else if(controls != 1){
    printf("Your search skill was not high enough\n");
}
}






if(ninjanum == 2){

        srand(time(NULL));
instructor = rand()% (two.stealth + 1);


if(instructor == 0){
    printf("Your ninja has been caught!\n");
    controls = 1;
}

if(temple_search[ninjalocater][ninjalocatec] <= two.search && controls != 1){
if(temple[ninjalocater][ninjalocatec] == 0){
    printf("you have discovered a trap\n");
    two.stealth--;
    temple_searched[ninjalocater][ninjalocatec] = 0;
}
if(temple[ninjalocater][ninjalocatec] == 1 && controls != 1){
    printf("you have discovered the katana\n");
    katana.found = 1;
    temple_searched[ninjalocater][ninjalocatec] = 1;
}
if(temple[ninjalocater][ninjalocatec] == 2 && controls != 1){
    printf("you have discovered the scroll\n");
    scroll.found = 1;
    temple_searched[ninjalocater][ninjalocatec] = 2;
}
if(temple[ninjalocater][ninjalocatec] == 3 && controls != 1){
    printf("you have discovered the Jade\n");
    jade.found = 1;
    temple_searched[ninjalocater][ninjalocatec] = 3;
}
if(temple[ninjalocater][ninjalocatec] == 4 && controls != 1){
    printf("you have discovered the mask\n");
    mask.found = 1;
    temple_searched[ninjalocater][ninjalocatec] = 4;
}
if(temple[ninjalocater][ninjalocatec] == 5 && controls != 1){
    printf("you have discovered nothing\n");
    temple_searched[ninjalocater][ninjalocatec] = 5;
}

                                              }
 else if(controls != 1){
    printf("Your search skill was not high enough\n");
}
}







if(ninjanum == 3){

        srand(time(NULL));
instructor = rand()% (three.stealth + 1);


if(instructor == 0){
    printf("Your ninja has been caught!\n");
    controls = 1;
}

if(temple_search[ninjalocater][ninjalocatec] <= three.search && controls != 1){
if(temple[ninjalocater][ninjalocatec] == 0){
    printf("you have discovered a trap\n");
    three.stealth--;
    temple_searched[ninjalocater][ninjalocatec] = 0;
}
if(temple[ninjalocater][ninjalocatec] == 1){
    printf("you have discovered the katana\n");
    katana.found = 1;
    temple_searched[ninjalocater][ninjalocatec] = 1;
}
if(temple[ninjalocater][ninjalocatec] == 2){
    printf("you have discovered the scroll\n");
    scroll.found = 1;
    temple_searched[ninjalocater][ninjalocatec] = 2;
}
if(temple[ninjalocater][ninjalocatec] == 3){
    printf("you have discovered the Jade\n");
    jade.found = 1;
    temple_searched[ninjalocater][ninjalocatec] = 3;
}
if(temple[ninjalocater][ninjalocatec] == 4){
    printf("you have discovered the mask\n");
    mask.found = 1;
    temple_searched[ninjalocater][ninjalocatec] = 4;
}
if(temple[ninjalocater][ninjalocatec] == 5){
    printf("you have discovered nothing\n");
    temple_searched[ninjalocater][ninjalocatec] = 5;
}

                                              }
 else if(controls != 1){
    printf("Your search skill was not high enough\n");
}
}






if(ninjanum == 4){

        srand(time(NULL));
instructor = rand()% (four.stealth + 1);

if(instructor == 0){
    printf("Your ninja has been caught!\n");
    controls = 1;
}

if(temple_search[ninjalocater][ninjalocatec] <= four.search && controls != 1){
if(temple[ninjalocater][ninjalocatec] == 0){
    printf("you have discovered a trap\n");
    four.stealth--;
    temple_searched[ninjalocater][ninjalocatec] = 0;
}
if(temple[ninjalocater][ninjalocatec] == 1){
    printf("you have discovered the katana\n");
    katana.found = 1;
    temple_searched[ninjalocater][ninjalocatec] = 1;
}
if(temple[ninjalocater][ninjalocatec] == 2){
    printf("you have discovered the scroll\n");
    scroll.found = 1;
    temple_searched[ninjalocater][ninjalocatec] = 2;
}
if(temple[ninjalocater][ninjalocatec] == 3){
    printf("you have discovered the Jade\n");
    jade.found = 1;
    temple_searched[ninjalocater][ninjalocatec] = 3;
}
if(temple[ninjalocater][ninjalocatec] == 4){
    printf("you have discovered the mask\n");
    mask.found = 1;
    temple_searched[ninjalocater][ninjalocatec] = 4;
}
if(temple[ninjalocater][ninjalocatec] == 5){
    printf("you have discovered nothing\n");
temple_searched[ninjalocater][ninjalocatec] = 5;

}

                                              }
else if(controls != 1){
    printf("Your search skill was not high enough\n");
}
hours--;

if(hours != -1){

printf("Ninja status \nsearch stealth\n N1: %d %d\n N2: %d %d\n N3: %d %d\n N4: %d %d\n", one.search, one.stealth , two.search, two.stealth , three.search, three.stealth , four.search, four.stealth);
}
}



controls = 0;
ninjanum++;
if(ninjanum == 5){
   ninjanum = 1;
}


if(katana.found == 1 && scroll.found == 1 && jade.found == 1 && mask.found == 1){
printf("You have retrieved all of the relics!");
    hours = -1;

}

}while(hours >= 0);


//If the user fails to collect all the relics
Relics_collected = katana.found + scroll.found + jade.found + mask.found;
if(Relics_collected != 4){

    printf("You are forced to leave the temple.  You retrieved %d relics for the Ninja Academy!", Relics_collected);

}





return 0;
}
//Pre condition two empty arrays
//Post condition two arrays filled with the stats of the map and the stats of the ninjas
void fill_in_arrays(int filled_map[18], int filled_ninjas[8]){
char input_file[100];
    printf("What is the name of the file ?\n");
scanf("%s", &input_file);

FILE *ifp = fopen(input_file, "r");





for(int z = 0; z < 18; z++){
fscanf(ifp, "%d", &filled_map[z]);

}

for(int w = 0; w < 8; w++){
    fscanf(ifp, "%d", &filled_ninjas[w]);

}
return;
}

void map_maker(int temple_searched[3][3]){

int control = 0;

        printf("This is the map:\n");
for(int x = 0;x < 3; x++){
for(int y = 0;y < 3; y++){


if(temple_searched[x][y] == 0){
            printf("Trap");
        }
if(temple_searched[x][y] == 1){
            printf("Katana");
        }

        if(temple_searched[x][y] == 2){
            printf("Scroll");
        }

        if(temple_searched[x][y] == 3){
            printf("Jade");
        }

        if(temple_searched[x][y] == 4){
            printf("Mask");
        }
if(temple_searched[x][y] == 5){
            printf("nothing");
        }

 if(temple_searched[x][y] == 6){
            printf("s");
        }


control++;


        if(control == 3){
control = 0;
    printf("\n");
}



}
}




return;
}
