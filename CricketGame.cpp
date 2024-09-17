#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

class Crick
{

public:
    string name;
    int id;
    int runScored;
    int ballsPlayed;
    int ballsBowled;
    int runsGiven;
    int wicketsTaken;

    // Constructor for class - Crick
    Crick()
    {
        runScored = 0;
        ballsPlayed = 0;
        ballsBowled = 0;
        runsGiven = 0;
        wicketsTaken = 0;
    }
};
class Team
{

public:
    string name;
    int totalRunsScored;
    int wicketsLost;
    int totalBallsBowled;
    vector<Crick> players;

// Constructor for class - Team
    Team()
    {
        totalRunsScored = 0;
        wicketsLost = 0;
        totalBallsBowled = 0;
    }
};
class Game
{

public:
    Game();
    int playersPerTeam;
    int maxBalls;
    int totalPlyers;
    string players[11];

    bool isFirstInnings;
    Team teamA, teamB;
    Team *battingTeam, *bowlingTeam;
    Crick *batsman, *bowler;

    void welcome();
    void showAllPlyaers();
    int takeIntegerInput();
    void selectPlayers();
    bool validateSelectedPlayer(int);
    void showTeamPlayers();
    void toss();
    void tossChoice(Team);
    void startFirstInnings();
    void initializePlayers();
    void playInnings();
    void bat();
    bool validateInningsScore();
    void showGameScoreCard();
    void startSecondInnigs();
    void showMatchSummary();
};

void Game ::welcome()
{

    cout << "|------------------------------------------------------------|\n";
    cout << "|                     CRICKET BLAST                          |\n";
    cout << "|------------------------------------------------------------|\n";
    cout << "|                                                            |\n";
    cout << "|           WELLCOME TO OUR VIRTUAL CRICKET GAME             |\n";
    cout << "|                                                            |\n";
    cout << "|------------------------------------------------------------|\n\n\n";

    cout << "|------------------------------------------------------------|\n";
    cout << "|                     GAME INSTRUCTIONS                      |\n";
    cout << "|------------------------------------------------------------|\n";
    cout << "|  1.Creat 2 teams (Team-A (MUMBAI INDIANS) & Team-b         |\n";
    cout << "| (PUNJAB KINGS) with 4 players each)form a given pool       |\n";
    cout << "|  of 11 players.                                            |\n";
    cout << "|  2.Lead the toss and decide the toss choice of play.       |\n";
    cout << "|  3.Each innings will be of 6 balls.                        |\n";
    cout << "|------------------------------------------------------------|\n\n";
}

Game ::Game()
{
    // List of Players

    playersPerTeam = 4;
    maxBalls = 6;
    totalPlyers = 11;

    players[0] = "Rohit Sharma";
    players[1] = "Hardik Pandya";
    players[2] = "MS Dhoni";
    players[3] = "Ishan Kishan";
    players[4] = "Virat Kohli";
    players[5] = "Jasprit Bumrah";
    players[6] = "Glen Maxwell";
    players[7] = "Mohmmad Siraj";
    players[8] = "Ravichandran Ashwin";
    players[9] = "KL Rahul";
    players[10] = "Ravindra Jadeja";

    isFirstInnings = false;
    teamA.name = "Mumbai Indians";
    teamB.name = "Punjab Kings";
}

void Game ::showAllPlyaers()
{
    cout << "-------------------------------------------------------------\n";
    cout << "|                      POOL OF PLAYERS                      |\n";
    cout << "-------------------------------------------------------------\n\n";

    for (int i = 0; i < totalPlyers; i++)
    {
        cout << "\t\t\t[" << i << "]" << players[i] << endl;
    }
}

int Game ::takeIntegerInput()
{

    int n;
    while (!(cin >> n))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buffer memory clean
        cout << "Invalid input!.Please try again with valid input" << endl;
    }
    return n;
}

bool Game ::validateSelectedPlayer(int index)

{

    int n;
    vector<Crick> players;

    players = teamA.players;
    n = players.size();
    for (int i = 0; i < n; i++)
    {

        if (players[i].id == index)
        {

            return false;
        }
    }
    players = teamB.players;
    n = players.size();
    for (int i = 0; i < n; i++)
    {

        if (players[i].id == index)
        {

            return false;
        }
    }
    return true;
}

void Game ::selectPlayers()
{

    cout << "|-----------------------------------------------------------|\n";
    cout << "|   ************   CREAT TEAM-A & TEAM-B   *************    |\n";
    cout << "|-----------------------------------------------------------|\n";
    cout << "|        TEAM-A            |          TEAM-B                |\n";
    cout << "|    (MUMBAI INDIANS)      |        (PUNJAB KINGS)          |\n";
    cout << "|-----------------------------------------------------------|\n\n";

    for (int i = 0; i < playersPerTeam; i++)
    {

    // For Team - A
    teamASelection:
        cout << "Select player " << i + 1 << " of Team A- ";

        int playerIndexTeamA = takeIntegerInput();

        if (playerIndexTeamA < 0 || playerIndexTeamA > 10)
        {

            cout << "Please select from the given players\n";
            goto teamASelection;
        }
        else if (!validateSelectedPlayer(playerIndexTeamA))
        {

            cout << "This player has been allready selected. Please select other player\n";
            goto teamASelection;
        }
        else
        {

            Crick teamAPlayer;
            teamAPlayer.id = playerIndexTeamA;
            teamAPlayer.name = players[playerIndexTeamA];
            teamA.players.push_back(teamAPlayer);
        }

    // For Team - B
    teamBSelection:

        cout << "Select player " << i + 1 << " of Team B- ";

        int playerIndexTeamB = takeIntegerInput();

        if (playerIndexTeamB < 0 || playerIndexTeamB > 10)
        {

            cout << "Please select from the given plyers\n";
            goto teamBSelection;
        }
        else if (!validateSelectedPlayer(playerIndexTeamB))
        {

            cout << "This player has been allready selected. Please select other player\n";
            goto teamBSelection;
        }
        else
        {

            Crick teamBPlayer;
            teamBPlayer.id = playerIndexTeamB;
            teamBPlayer.name = players[playerIndexTeamB];
            teamB.players.push_back(teamBPlayer);
        }
    }
}

// List of selected player for both teams

void Game ::showTeamPlayers()
{

    vector<Crick> teamAPlayers = teamA.players;
    vector<Crick> teamBPlayers = teamB.players;

    cout << "\n\n";
    cout << "|---------------------------------------------------------------|\n";
    cout << "|           TEAM-A             |            TEAM-B              |\n";
    cout << "|      (MUMBAI INDIANS)        |        (PUNJAB KINGS)          |\n";
    cout << "|---------------------------------------------------------------|\n";

    for (int i = 0; i < playersPerTeam; i++)
    {

        cout << "|\t" << "[" << i << "]" << teamAPlayers[i].name << "\t|"
             << "\t\t"
             << "|\t" << "[" << i << "]" << teamBPlayers[i].name << "\t|" << endl;
    }
    cout << "------------------------\t\t-------------------------" << endl;
}

void Game ::toss()
{

    cout << "-------------------------------------------------------\n";
    cout << "|  ===========  This time is Toss time   ============  |\n";
    cout << "-------------------------------------------------------\n\n";

    cout << "Tossing the coin....\n";

    int randomValue;
    srand(time(NULL));
    randomValue = rand() % 2;     // 0 or 1

    switch (randomValue)
    {

    case 0:
        cout << "Team-A (MUMBAI INDIANS) won the toss" << endl
             << endl;
        tossChoice(teamA);
        break;

    case 1:
        cout << "Team-B (PUNJAB KINGS) won the toss" << endl
             << endl;
        tossChoice(teamB);
        break;
    }
}

void Game ::tossChoice(Team tosswinnerTeam)
{

    cout << "Enter 1 To Bat First or 2 To Bowl First." << endl
         << "1. Bat" << endl
         << "2. Bowl" << endl;

    int tossInput = takeIntegerInput();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (tossInput)
    {

    case 1:
        cout << endl
             << tosswinnerTeam.name << " have won the toss and elected to bat first" << endl
             << endl;

        if (tosswinnerTeam.name.compare("Mumbai Indians") == 0)
        {
            battingTeam = &teamA;
            bowlingTeam = &teamB;
        }
        else
        {
            battingTeam = &teamB;
            bowlingTeam = &teamA;
        }
        break;

    case 2:
        cout << endl
             << tosswinnerTeam.name << " have won the toss and elected to  bowl first" << endl
             << endl;

        if (tosswinnerTeam.name.compare("Mumbai Indians") == 0)
        {
            bowlingTeam = &teamA;
            battingTeam = &teamB;
        }
        else
        {
            bowlingTeam = &teamB;
            battingTeam = &teamA;
        }
        break;

    default:
        cout << endl
             << "Invalid input. Please try again:" << endl
             << endl;
        tossChoice(tosswinnerTeam);
        break;
    }
}

void Game ::startFirstInnings()
{

    cout << "\t\t----------------------------------------\n";
    cout << "\t\t|        FIRST INNINGS STARTS          |\n";
    cout << "\t\t----------------------------------------\n\n";

    isFirstInnings = true;

    initializePlayers();
    playInnings();
}

void Game ::startSecondInnigs()
{

    cout << "\t\t----------------------------------------\n";
    cout << "\t\t|        SECOND INNINGS STARTS         |\n";
    cout << "\t\t----------------------------------------\n\n";

    isFirstInnings = false;

    // swap batting and bowling team pointer
    Team tempTeam = *battingTeam;
    *battingTeam = *bowlingTeam;
    *bowlingTeam = tempTeam;

    initializePlayers();
    playInnings();
}

void Game ::initializePlayers()
{

    batsman = &battingTeam->players[0];
    bowler = &bowlingTeam->players[0];

    cout << battingTeam->name << " - " << batsman->name << " is batting" << endl
         << endl;
    cout << bowlingTeam->name << " - " << bowler->name << " is bowling" << endl;
}

void Game ::playInnings()
{

    for (int i = 0; i < maxBalls; i++)
    {

        cout << "Press enter to bowl...";
        getchar();
        cout << "Bowling....." << endl;

        bat();

        if (!validateInningsScore())
        {
            break;
        }
    }
}

void Game ::bat()
{

    int runScored;
    srand(time(NULL));
    runScored = rand() % 7;

    // Batting team and batsman update
    batsman->runScored = batsman->runScored + runScored;
    battingTeam->totalRunsScored = battingTeam->totalRunsScored + runScored;
    batsman->ballsPlayed = batsman->ballsPlayed + 1;

    // Bowling team and bowler update
    bowler->ballsBowled = bowler->ballsBowled + 1;
    bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
    bowler->runsGiven = bowler->runsGiven + runScored;

    if (runScored != 0)
    {
        // runScored = 1,2,3,4,5,6.
        cout << endl
             << bowler->name << " to " << batsman->name << " " << runScored << " runs!" << endl
             << endl;
        showGameScoreCard();
    }
    else
    {
        cout << endl
             << bowler->name << " to " << batsman->name << " OUT!" << endl
             << endl;

        battingTeam->wicketsLost = battingTeam->wicketsLost + 1;
        bowler->wicketsTaken = bowler->wicketsTaken + 1;

        showGameScoreCard();

        // For Next Player after wicket
        int nextPlayerIndex = battingTeam->wicketsLost;
        batsman = &battingTeam->players[nextPlayerIndex];
    }
}

bool Game ::validateInningsScore()
{

    if (isFirstInnings)
    {

        if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls)
        {

            cout << "\t\t|| FIRST INNINGS ENDS || " << endl
                 << endl;

            cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
                 << battingTeam->wicketsLost << "(" << bowlingTeam->totalBallsBowled
                 << ")" << endl;
            cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1
                 << " runs to win the match" << endl
                 << endl;

            return false;
        }
    }
    else
    {
        if (battingTeam->totalRunsScored > bowlingTeam->totalRunsScored)
        {

            cout << battingTeam->name << " WON THE MATCH " << endl
                 << endl;

            return false;
        }
        else if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls)
        {

            if (battingTeam->totalRunsScored < bowlingTeam->totalRunsScored)
            {

                cout << bowlingTeam->name << " WON THE MATCH " << endl
                     << endl;
            }
            else
            {

                cout << "MATCH DRAW" << endl
                     << endl;
            }

            return false;
        }
    }
    return true;
}

void Game ::showGameScoreCard()
{

    cout << "------------------------------------------------------------------------------\n";

    cout << "\t" << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
         << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ") |"<< batsman->name
         << " "<< batsman->runScored << " (" << batsman->ballsPlayed << ") \t" << bowler->name << " "
         << bowler->ballsBowled << " - " << bowler->runsGiven << " - " << bowler->wicketsTaken << "\t" << endl;

    cout << "------------------------------------------------------------------------------\n";
}

void Game ::showMatchSummary()
{

    cout << "\t\t-----------------------------------------------\n";
    cout << "\t\t|               MATCH ENDS                    |\n";
    cout << "\t\t-----------------------------------------------\n\n";

    cout << battingTeam->name << " " << battingTeam->totalRunsScored << "-" << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ")" << endl;

    cout << "****************************************************" << endl;
    cout << "| PLAYER \t BATTING \t BOWLING \t |" << endl;

    for (int j = 0; j < playersPerTeam; j++)
    {

        Crick crick = battingTeam->players[j];
        cout << "|-----------------------------------------------|" << endl;
        cout << "|"
             << "[" << j << "]" << crick.name << " \t"
             << crick.runScored << "(" << crick.ballsBowled << ") \t\t"
             << crick.ballsBowled << "-" << crick.runsGiven << "-"
             << crick.wicketsTaken << "\t |" << endl;
    }
    cout << "**************************************************" << endl;

    cout << bowlingTeam->name << " " << bowlingTeam->totalRunsScored << "-" << bowlingTeam->wicketsLost << "(" << battingTeam->totalBallsBowled << ")" << endl;

    cout << "**************************************************" << endl;
    cout << "| PLAYER \t BATTING \t BOWLING \t |" << endl;

    for (int i = 0; i < playersPerTeam; i++)
    {

        Crick crick = bowlingTeam->players[i];
        cout << "|----------------------------------------------|" << endl;
        cout << "|"
             << "[" << i << "]" << crick.name << " \t"
             << crick.runScored << "(" << crick.ballsBowled << ") \t\t"
             << crick.ballsBowled << "-" << crick.runsGiven << "-"
             << crick.wicketsTaken << "\t |" << endl;
    }
    cout << "****************************************************" << endl;
}

int main()
{

    Game game;
    game.welcome();

    cout << "Press enter to continue..." << endl;
    getchar();
    sleep(2);

    game.showAllPlyaers();

    cout << "Press enter to continue..." << endl;
    getchar();

    game.selectPlayers();

    game.showTeamPlayers();

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // For clean the Buffer memory

    cout << "Press enter to continue..." << endl;
    getchar();
    sleep(2);

    game.toss();

    game.startFirstInnings();

    game.startSecondInnigs();
    sleep(2);

    game.showMatchSummary();

    return 0;
}