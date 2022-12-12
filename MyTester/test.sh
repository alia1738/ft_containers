#!/bin/bash

blue=`tput setab 219`
face=`tput setaf 223`
faceOutline=`tput setaf 222`
gray=`tput setaf 244`
grayfill=`tput setab 242`
jeans=`tput setaf 26`
shirt=`tput setaf 124`
shoes=`tput setaf 255`
hair=`tput setaf 208`
lip=`tput setaf 205`
computer=`tput setaf 87`
table=`tput setaf 216`
red=`tput setaf 160`
reset=`tput sgr0`

blueToPurple1=`tput setaf 20`
blueToPurple2=`tput setaf 56`
blueToPurple3=`tput setaf 92`
blueToPurple4=`tput setaf 128`
blueToPurple5=`tput setaf 164`
blueToPurple6=`tput setaf 200`

greenToOrange1=`tput setaf 28`
greenToOrange2=`tput setaf 64`
greenToOrange3=`tput setaf 100`
greenToOrange4=`tput setaf 136`
greenToOrange5=`tput setaf 172`
greenToOrange6=`tput setaf 208`

blueToPink1=`tput setaf 33`
blueToPink2=`tput setaf 69`
blueToPink3=`tput setaf 105`
blueToPink4=`tput setaf 141`
blueToPink5=`tput setaf 177`
blueToPink6=`tput setaf 213`

lightyellow=`tput setaf 230`
yellow=`tput setaf 229`
starB=`tput setaf 159`
starPk=`tput setaf 224`
starPr=`tput setaf 189`
starAq=`tput setaf 158`
white=`tput setaf 15`


alien1=`tput setaf 22`
alien2=`tput setaf 24`
alien3=`tput setaf 208`
alien4=`tput setaf 129`
alien5=`tput setaf 34`
alieneye=`tput setaf 244`

AllAfterTestingArt() {
	sleep 0.1
	echo ""
	echo "${alien1}           .-\"\"\"\"-.   ${alien2}    .-\"\"\"\"-."
	echo "${alien1}          /        \  ${alien2}   /        \\"
	echo "${alien1}         /_        _\ ${alien2}  /_        _\\"
	echo "${alien1}        // \      / \\\\${alien2} // \      / \\\\"
	echo "${alien1}        |\__\    /__/|${alien2} |\__\    /__/|"
	echo "${alien1}         \    ||    / ${alien2}  \    ||    /"
	echo "${alien1}          \        /  ${alien2}   \        /"
	sleep 0.1
	echo "${alien1}           \  __  /   ${alien2}    \  __  /"
	echo "${alien3}   .-\"\"\"\"-.${alien1} '.__.'${alien4}.-\"\"\"\"-.${alien2} '.__.'${alien5}.-\"\"\"\"-."
	echo "${alien3}  /        \\${alien1} |  |${alien4}/        \\${alien2} |  |${alien5}/        \\"
	echo "${alien3} /_        _\\${alien1}|  ${alien4}/_        _\\${alien2}|${alien5}  /_        _\\"
	echo "${alien3}// \      / \\\\${alien4} // \      / \\\\ ${alien5}// \      / \\\\"
	echo "${alien3}|\__\    /__/|${alien4} |\__\    /__/| ${alien5}|\__\    /__/|"
	sleep 0.1
	echo "${alien3} \    ||    / ${alien4}  \    ||    /  ${alien5} \    ||    /"
	echo "${alien3}  \        /  ${alien4}   \        /   ${alien5}  \        /"
	echo "${alien3}   \  __  /   ${alien4}    \  __  /    ${alien5}   \  __  /"
	echo "${alien3}    '.__.'    ${alien4}     '.__.'     ${alien5}    '.__.'"
	echo "${alien3}     |  |     ${alien4}      |  |      ${alien5}     |  |"
	echo "${alien3}     |  |     ${alien4}      |  |      ${alien5}     |  |"
	sleep 0.1
}

stackAfterTestingArt() {
	sleep 0.1
	echo ""
	echo " ${starB}       *   ${starPk}'${starB}*"
	echo " ${starPr}               *"
	echo " ${starPr}                    *"
	echo " ${starAq}                           *"
	echo " ${starAq}                   *"
	echo " ${starPk}                         *"
	sleep 0.1
	echo ""
	echo "${yellow}              .                      ."
	echo "${yellow}              .                      ;"
	echo "${yellow}              :                  - --${white}+${yellow}-- -"
	echo "${yellow}              !     ${starB}      .   ${yellow}       !"
	echo "${yellow}              |     ${starAq}   .      ${yellow}       ."
	echo "${yellow}             _|_    ${starB}     +"
	sleep 0.1
	echo "${yellow}           ,${white}  | ${yellow}\`."
	echo "${yellow}- -- --- --+${white}-<#>-${yellow}+- ---  --  -"
	echo "${yellow}           \`._${reset}|${yellow}_,'"
	echo "${yellow}              T"
	echo "${yellow}              |"
	echo "${yellow}              !"
	echo "${yellow}              :     ${starPr}    . : "
	echo "${yellow}              .     ${starPk}  *"
	echo ""
	sleep 0.1
}

mapAfterTestingArt() {
	sleep 0.1
	echo ""
	echo "${gray}    _"
	echo "${gray}   | |"
	echo "${gray}   | |===${face}( )  ${hair} //////"
	sleep 0.1
	echo "${gray}   |_|  ${shirt} ||| ${face} | ${red}o o${face}|${reset}"
	echo "${shirt}          ||| ${face}(  ${faceOutline}c ${face})     ${computer}             ____"
	echo "${shirt}          ||| ${face} \ ${lip}=${face}/      ${computer}            ||   \_${reset}"
	echo "${shirt}            ||||||       ${computer}            ||     |${reset}"
	sleep 0.1
	echo "${shirt}            ||||||       ${computer}         ...||__/|-${reset}"
	echo "${shirt}            ||||||       ${table}      __${computer}|${table}________${computer}|${table}__${reset}"
	echo "${jeans}              |||        ${table}     |______________|${reset}"
	sleep 0.1
	echo "${jeans}              |||        ${table}     || ||      || ||${reset}"
	echo "${jeans}              |||        ${table}     || ||      || ||${reset}"
	echo "--------------${jeans}|||${reset}-------------${table}||${reset}-${table}||${reset}------${table}||${reset}-${table}||${reset}-------"
	echo "              ${shirt}|__>            ${table}|| ||      || ||${reset}"
	sleep 0.1
}

testingArt(){
	echo "${blueToPurple5} _____   ${blueToPurple4}      _  ${blueToPurple3} _  "                 
	echo "${blueToPurple5}|_   _|   ${blueToPurple4}    | | ${blueToPurple3}(_) "                 
	echo "${blueToPurple5}  | | ___ ${blueToPurple4} ___| |_${blueToPurple3} _ _ __  ${blueToPurple2} __ _ "      
	echo "${blueToPurple5}  | |/ _ \\${blueToPurple4}/ __| __${blueToPurple3}| | '_ \\${blueToPurple2} / _\` | "     
	echo "${blueToPurple5}  | |  __/${blueToPurple4}\__ \ |_${blueToPurple3}| | | | |${blueToPurple2} (_| |_ _ _ "
	echo "${blueToPurple5}  \_/\___|${blueToPurple4}|___/\__${blueToPurple3}|_|_| |_|${blueToPurple2}\__, (_|_|_)"
	echo "                         ${blueToPurple2}   __/ |      "
	echo "                         ${blueToPurple2}  |___/       ${reset}"
}

vectorAfterTestingArt() {
	# greenToOrange1
	# greenToOrange1
	echo ""
	echo "${greenToOrange1}    |\ | |  ||\ \ /(_~     |~)|_~|\/||_~|\/||~)|_~|~)${reset}"
	echo "${greenToOrange1}    |~\|_|/\||~\ | ,_)     |~\|__|  ||__|  ||_)|__|~\\"
	sleep 0.1
	echo ""
	echo "${greenToOrange1}       \ //~\| |    |\ |~)|_~    | ||\ ||/~\| ||_~"
	echo "${greenToOrange1}        | \_/\_/    |~\|~\|__    \_/| \||\_X\_/|__${reset}"
	sleep 0.1
	echo ""
	echo -e "\033[2m" "     (${greenToOrange6}J U S T   L I K E   E V E R Y O N E   E L S E${reset}\033[2m)${reset}"
	sleep 0.1
	echo "${greenToOrange1}      _____         _____         _____         _____    ${reset}"
	echo "${greenToOrange1}    .'     '.     .'     '.     .'     '.     .'     '.  ${reset}"
	echo "${greenToOrange1}   /  o   o  \   /  o   o  \   /  o   o  \   /  o   o  \ ${reset}"
	echo "${greenToOrange1}  |           | |           | |           | |           |${reset}"
	echo "${greenToOrange2}  |  \     /  | |  \     /  | |  \     /  | |  \     /  |${reset}"
	echo "${greenToOrange2}   \  '---'  /   \  '---'  /   \  '---'  /   \  '---'  / ${reset}"
	echo "${greenToOrange2}    '._____.'     '._____.'     '._____.'     '._____.'  ${reset}"
	sleep 0.1
	echo "${greenToOrange3}      _____         _____         _____         _____    ${reset}"
	echo "${greenToOrange3}    .'     '.     .'     '.     .'     '.     .'     '.  ${reset}"
	echo "${greenToOrange3}   /  o   o  \   /  o   o  \   /  o   o  \   /  o   o  \ ${reset}"
	echo "${greenToOrange3}  |           | |           | |           | |           |${reset}"
	echo "${greenToOrange4}  |  \     /  | |  \     /  | |  \     /  | |  \     /  |${reset}"
	echo "${greenToOrange4}   \  '---'  /   \  '---'  /   \  '---'  /   \  '---'  / ${reset}"
	echo "${greenToOrange4}    '._____.'     '._____.'     '._____.'     '._____.'  ${reset}"
	sleep 0.1
	echo "${greenToOrange5}      _____         _____         _____         _____    ${reset}"
	echo "${greenToOrange5}    .'     '.     .'     '.     .'     '.     .'     '.  ${reset}"
	echo "${greenToOrange5}   /  o   o  \   /  o   o  \   /  o   o  \   /  o   o  \ ${reset}"
	echo "${greenToOrange6}  |           | |           | |           | |           |${reset}"
	echo "${greenToOrange6}  |  \     /  | |  \     /  | |  \     /  | |  \     /  |${reset}"
	echo "${greenToOrange6}   \  '---'  /   \  '---'  /   \  '---'  /   \  '---'  / ${reset}"
	echo "${greenToOrange6}    '._____.'     '._____.'     '._____.'     '._____.'  ${reset}"
	echo ""
	sleep 0.1

}


vectorArt(){
	echo "${blueToPink6} __   __ ${blueToPink5} _______ ${blueToPink4} _______ ${blueToPink3} _______ ${blueToPink2} _______ ${blueToPink1} ______  " 
	echo "${blueToPink6}|  | |  |${blueToPink5}|       |${blueToPink4}|       |${blueToPink3}|       |${blueToPink2}|       |${blueToPink1}|    _ |  "
	echo "${blueToPink6}|  |_|  |${blueToPink5}|    ___|${blueToPink4}|       |${blueToPink3}|_     _|${blueToPink2}|   _   |${blueToPink1}|   | ||  "
	echo "${blueToPink6}|       |${blueToPink5}|   |___ ${blueToPink4}|       |${blueToPink3}  |   |  ${blueToPink2}|  | |  |${blueToPink1}|   |_||_ "
	echo "${blueToPink6}|       |${blueToPink5}|    ___|${blueToPink4}|      _|${blueToPink3}  |   |  ${blueToPink2}|  |_|  |${blueToPink1}|    __  |"
	echo "${blueToPink6} |     | ${blueToPink5}|   |___ ${blueToPink4}|     |_ ${blueToPink3}  |   |  ${blueToPink2}|       |${blueToPink1}|   |  | |"
	echo "${blueToPink6}  |___|  ${blueToPink5}|_______|${blueToPink4}|_______|${blueToPink3}  |___|  ${blueToPink2}|_______|${blueToPink1}|___|  |_| ${reset}"
	echo ""
}

mapArt() {
	echo "${blueToPink6} __  ${blueToPink5} __ ${blueToPink4} ___${blueToPink3}____ ${blueToPink2} ___${blueToPink1}____ "
	echo "${blueToPink6}|  |_${blueToPink5}|  |${blueToPink4}|   ${blueToPink3}_   |${blueToPink2}|   ${blueToPink1}    |"
	echo "${blueToPink6}|    ${blueToPink5}   |${blueToPink4}|  |${blueToPink3}_|  |${blueToPink2}|   ${blueToPink1} _  |"
	echo "${blueToPink6}|    ${blueToPink5}   |${blueToPink4}|   ${blueToPink3}    |${blueToPink2}|   ${blueToPink1}|_| |"
	echo "${blueToPink6}|    ${blueToPink5}   |${blueToPink4}|   ${blueToPink3}    |${blueToPink2}|   ${blueToPink1} ___|"
	echo "${blueToPink6}| ||_${blueToPink5}|| |${blueToPink4}|   ${blueToPink3}_   |${blueToPink2}|   ${blueToPink1}|    "
	echo "${blueToPink6}|_|  ${blueToPink5} |_|${blueToPink4}|__|${blueToPink3} |__|${blueToPink2}|___${blueToPink1}|    ${reset}"
	echo ""
}

stackArt() {
	echo "${blueToPink6} _______${blueToPink5}  ______${blueToPink4}_  _____${blueToPink3}__  ___${blueToPink2}____  ${blueToPink1}___   _ ${reset}"
	echo "${blueToPink6}|       ${blueToPink5}||      ${blueToPink4} ||   _ ${blueToPink3}  ||   ${blueToPink2}    ||${blueToPink1}   | | |${reset}"
	echo "${blueToPink6}|  _____${blueToPink5}||_     ${blueToPink4}_||  |_|${blueToPink3}  ||   ${blueToPink2}    ||${blueToPink1}   |_| |${reset}"
	echo "${blueToPink6}| |_____${blueToPink5}   |   |${blueToPink4}  |     ${blueToPink3}  ||   ${blueToPink2}    ||${blueToPink1}      _|${reset}"
	echo "${blueToPink6}|_____  ${blueToPink5}|  |   |${blueToPink4}  |     ${blueToPink3}  ||   ${blueToPink2}   _||${blueToPink1}     |_ ${reset}"
	echo "${blueToPink6} _____| ${blueToPink5}|  |   |${blueToPink4}  |   _ ${blueToPink3}  ||   ${blueToPink2}  |_ |${blueToPink1}    _  |${reset}"
	echo "${blueToPink6}|_______${blueToPink5}|  |___|${blueToPink4}  |__| |${blueToPink3}__||___${blueToPink2}____||${blueToPink1}___| |_|${reset}"
}

allArt() {
	echo "${blueToPink6} _______ ${blueToPink5} ___     ${blueToPink4} ___     ${blueToPink3} __  ${blueToPink2} __  ${blueToPink1} __  ${reset}"
	echo "${blueToPink6}|   _   |${blueToPink5}|   |    ${blueToPink4}|   |    ${blueToPink3}|  | ${blueToPink2}|  | ${blueToPink1}|  | ${reset}"
	echo "${blueToPink6}|  |_|  |${blueToPink5}|   |    ${blueToPink4}|   |    ${blueToPink3}|  | ${blueToPink2}|  | ${blueToPink1}|  | ${reset}"
	echo "${blueToPink6}|       |${blueToPink5}|   |    ${blueToPink4}|   |    ${blueToPink3}|  | ${blueToPink2}|  | ${blueToPink1}|  | ${reset}"
	echo "${blueToPink6}|       |${blueToPink5}|   |___ ${blueToPink4}|   |___ ${blueToPink3}|__| ${blueToPink2}|__| ${blueToPink1}|__| ${reset}"
	echo "${blueToPink6}|   _   |${blueToPink5}|       |${blueToPink4}|       |${blueToPink3} __  ${blueToPink2} __  ${blueToPink1} __  ${reset}"
	echo "${blueToPink6}|__| |__|${blueToPink5}|_______|${blueToPink4}|_______|${blueToPink3}|__| ${blueToPink2}|__| ${blueToPink1}|__| ${reset}"
}

CheckDiff() {

	diff "ft_$1.txt" "std_$1.txt" > diff.txt
	if [ -s diff.txt ]; then
		# not empty
		rm -rf diff.txt
		echo "${blueToPink4}♦︎ "${blueToPink1}$1 "$2❌${reset}"
	else
		# empty
		rm -rf diff.txt
		echo "${blueToPink4}♦︎ "${blueToPink1}$1 "$2✅${reset}"
	fi
}

GetTime() {
	echo " ----------------------------------------${blueToPurple6}"
	cat ft_time.txt;
	# echo "${reset}" "${blueToPink1}"
	echo "${reset}" "${blueToPurple1}"
	cat std_time.txt;
	echo "${reset} ----------------------------------------"
}

VectorTest() {
	if [ ! -d VectorTest ]; then
		mkdir VectorTest
	fi
	cd VectorTest

	c++ ../../testVector.cpp -o std_VEC
	if [ -x ./std_VEC ]; then 
		./std_VEC
		# valgrind ./std_VEC
	fi
	c++ ../../testVector.cpp -g3 -o ft_VEC -D FT=1
	if [ -x ./ft_VEC ]; then 
		# ./ft_VEC
		valgrind --leak-check=full ./ft_VEC
	fi

	CheckDiff "constructors" "				"
	sleep 0.5
	CheckDiff "element_access" "			"
	sleep 0.5
	CheckDiff "iterator" "				"
	sleep 0.5
	CheckDiff "capasity" "				"
	sleep 0.5
	CheckDiff "modifiers" "				"
	sleep 0.5
	CheckDiff "non_member_functions" "			"
	sleep 0.5

	GetTime

	rm -rf ft_VEC std_VEC

	cd ..
}

MapTest() {
	if [ ! -d MapTest ]; then
		mkdir MapTest
	fi
	cd MapTest

	c++ ../../testMap.cpp -o std_MAP
	if [ -x ./std_MAP ]; then 
		./std_MAP
		# valgrind ./std_MAP
	fi
	c++ ../../testMap.cpp -g3 -o ft_MAP -D FT=1
	if [ -x ./ft_MAP ]; then 
		# ./ft_MAP
		valgrind --leak-check=full ./ft_MAP
	fi

	CheckDiff "constructors" "				"
	sleep 0.5
	CheckDiff "element_access" "			"
	sleep 0.5
	CheckDiff "iterator" "				"
	sleep 0.5
	CheckDiff "capacity" "				"
	sleep 0.5
	CheckDiff "modifiers" "				"
	sleep 0.5
	CheckDiff "observers" "				"
	sleep 0.5
	CheckDiff "operations" "				"
	sleep 0.5
	CheckDiff "non_member_functions" "			"
	sleep 0.5

	GetTime

	rm -rf ft_MAP std_MAP

	cd ..
}

StackTest() {
	if [ ! -d StackTest ]; then
		mkdir StackTest
	fi
	cd StackTest

	c++ ../../testStack.cpp -o std_STACK
	if [ -x ./std_STACK ]; then 
		./std_STACK
		# valgrind ./std_STACK
	fi
	c++ ../../testStack.cpp -g3 -o ft_STACK -D FT=1
	if [ -x ./ft_STACK ]; then 
		# ./ft_STACK
		valgrind --leak-check=full --show-leak-kinds=all ./ft_STACK
	fi

	CheckDiff "constructors" "				"
	sleep 0.5
	CheckDiff "element_access" "			"
	sleep 0.5
	CheckDiff "capacity" "				"
	sleep 0.5
	CheckDiff "modifiers" "				"
	sleep 0.5
	CheckDiff "non_member_functions" "			"
	sleep 0.5

	GetTime

	rm -rf ft_STACK std_STACK

	cd ..
}

AllTset() {
	vectorArt
	VectorTest

	mapArt
	MapTest

	stackArt
	StackTest
}


clear
echo "${blueToPurple6} _____ _   ${blueToPurple5}            ${blueToPurple4}               ${blueToPurple3}_        ${blueToPurple2}    _       "
echo "${blueToPurple6}/  __ \ |  ${blueToPurple5}            ${blueToPurple4}              |${blueToPurple3} |       ${blueToPurple2}   | |    _ "
echo "${blueToPurple6}| /  \/ |__${blueToPurple5}   ___  ___ ${blueToPurple4} ___    __ _  |${blueToPurple3} |_ ___  ${blueToPurple2}___| |_  (_)"
echo "${blueToPurple6}||    | '_ ${blueToPurple5}\ / _ \/ __|${blueToPurple4}/ _ \  / _\` | ${blueToPurple3}| __/ _ \\${blueToPurple2}/ __| __|    "
echo "${blueToPurple6}| \__/\ | |${blueToPurple5} | (_) \__ \\${blueToPurple4}  __/ | (_| | |${blueToPurple3} ||  __/${blueToPurple2}\__ \ |_   _ "
echo "${blueToPurple6} \____/_| |${blueToPurple5}_|\___/|___/${blueToPurple4}\___|  \__,_|  ${blueToPurple3}\__\___|${blueToPurple2}|___/\__| (_)${reset}"
echo ""
echo "[ ${blueToPurple5}1 ${reset}] ${blueToPurple6}vector${reset}"
echo "[ ${blueToPurple4}2 ${reset}] ${blueToPurple4}map${reset}"
echo "[ ${blueToPurple3}3 ${reset}] ${blueToPurple3}stack${reset}"
echo "[ ${blueToPurple2}4 ${reset}] ${blueToPurple2}all${reset}"

read test_type

if [ ! -d test_results ]; then 
	mkdir test_results
fi
cd test_results

if [ $test_type == 1 ]; then 
	vectorArt
	# testingArt
	VectorTest
	vectorAfterTestingArt


elif [ $test_type == 2 ]; then
	mapArt
	MapTest
	mapAfterTestingArt

elif [ $test_type == 3 ]; then
	stackArt
	StackTest
	stackAfterTestingArt

elif [ $test_type == 4 ]; then
	allArt
	AllTset
	AllAfterTestingArt

else
	cd ..
	rm -rf test_results
	echo "${red}Invalid choice"
fi

#  _______  _______  _______  _______  ___   __    _  _______                   
# |       ||       ||       ||       ||   | |  |  | ||       |                  
# |_     _||    ___||  _____||_     _||   | |   |_| ||    ___|                  
#   |   |  |   |___ | |_____   |   |  |   | |       ||   | __                   
#   |   |  |    ___||_____  |  |   |  |   | |  _    ||   ||  | ___   ___   ___  
#   |   |  |   |___  _____| |  |   |  |   | | | |   ||   |_| ||   | |   | |   | 
#   |___|  |_______||_______|  |___|  |___| |_|  |__||_______||___| |___| |___| 

#  _____         _   _                   
# |_   _|       | | (_)                  
#   | | ___  ___| |_ _ _ __   __ _       
#   | |/ _ \/ __| __| | '_ \ / _` |      
#   | |  __/\__ \ |_| | | | | (_| |_ _ _ 
#   \_/\___||___/\__|_|_| |_|\__, (_|_|_)
#                             __/ |      
#                            |___/       

#               _
#              | |
#              | |===( )   //////
#              |_|   |||  | o o|
#                     ||| ( c  )                  ____
#                      ||| \= /                  ||   \_
#                       ||||||                   ||     |
#                       ||||||                ...||__/|-"
#                       ||||||             __|________|__
#                         |||             |______________|
#                         |||             || ||      || ||
#                         |||             || ||      || ||
# ------------------------|||-------------||-||------||-||-------
#                         |__>            || ||      || ||
