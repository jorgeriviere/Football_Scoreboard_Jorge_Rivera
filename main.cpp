#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

class Team
{
private:
  string name;
  string Coach_Name;
  string Home_City;
  int score;
  bool Home_Status;
  int Timeout_Count;
public:
    Team ()			//default constructor
  {
    score = 0;
    Home_Status = false;	//visitor = false, home = true
    name = "Default";
    Coach_Name= "Default";
    Home_City="Default";
    Timeout_Count = 0;
  }
  void setScore (int s)
  {
    score = s;
  }
  void setHome_Status (bool hs)
  {
    Home_Status = hs;
  }
  void setName (string n)
  {
    name = n;
  }
  void setTimeout_Count (int tc)
  {
    Timeout_Count = tc;
  }
  void setCoach_Name (string cm)
  {
    Coach_Name = cm;
  }
  void setHome_City (string hc)
  {
    Home_City = hc;
  }
  int getScore () const
  {
    return score;
  }
  bool getHome_Status () const
  {
    return Home_Status;
  }
  string getName () const
  {
    return name;
  }
  string getCoach_Name () const
  {
    return Coach_Name;
  }
  string getHome_City () const
  {
    return Home_City;
  }
  int getTimeout_Count () const
  {
    return Timeout_Count;
  }
};

class Scoreboard
{
private:
  int half;
  Team home;			//object that is a member of another object
  Team visitor;
public:
    Scoreboard ()
  {
    half = 0;
  }
  void setHalf (int h)
  {
    half = h;
  }
  void setHome (Team hSet)
  {
    home = hSet;
  }
  void setVisitor (Team vSet)
  {
    visitor = vSet;
  }
  int getHalf () const
  {
    return half;
  }
  Team getHome () const
  {
    return home;
  }
  Team getVisitor () const
  {
    return visitor;
  }
  void showScoreboard ()
  {				///////DISPLAY BOARD******
    string color = "";
    string reset = "\x1b[0m";
    color = "\x1b[44m\x1b[4m";	//blue letter, underlined
    cout<<"#####################################"<< endl;
    cout <<"#"<< color << "\t\t"<<"¡American Football!" << reset << "\t\t\t"<<"#"<< endl;
    string score;	//score color
    color="\x1b[45m";
    cout <<"#" <<"\t\t" <<color<<"Home"<<"\t\t"<<"Visitor" <<reset<< "\t\t\t"<<"#"<< endl;
    cout <<"#"<<"\t\t" <<home.getName () << "\t\t" << visitor.getName () <<"\t\t\t"<<"#"<< endl;
        cout <<"#"<<"Scores"<<"\t"<< score << home.getScore () << "\t\t\t" << visitor.
        getScore ()<<"\t\t\t\t"<<"#"<< endl;
    cout <<"#"<< "Coach"<<"\t" <<home.getCoach_Name () << reset << "\t\t" << visitor.
        getCoach_Name () <<"\t\t\t"<<"#"<< endl;
    cout <<"#"<<"Cities" <<"\t"<<home.getHome_City () << reset << "\t\t" << visitor.
      getHome_City () <<"\t\t\t"<<"#"<< endl;
      cout <<"#"<<"\t\t\t"<<"Timeout"<<"\t\t\t\t\t"<<"#"<< endl;
      cout<<"#"<<"\t\t\t\t"<<home.getTimeout_Count() << reset <<"\t\t\t\t\t"<<"#"<< endl;
      cout<<"#####################################"<< endl;
  }
};

int
main ()
{
  Scoreboard s;
  Team tOne;
  Team tTwo;
  string newNameA = "";
  string newNameB = "";
  string userChoice = "";
  string newCoachA = "";
  string newCoachB = "";
  string newCityA = "";
  string newCityB = "";
  int timeout=0;
  int newScore = 0;
  tOne.setHome_Status (true);	//tOne is the Home Team now   
  s.setHome (tOne);		//add some initial data to s
  s.setVisitor (tTwo);
  do
    {
//system("clear"); //clear the screen of previous content
      s.showScoreboard ();	//show the current scoreboard data
//menu choices
      cout << "A = Update Team Names" << endl;
      cout << "B = Update Scores" << endl;
      cout << "C = Update Coach names" << endl;
      cout << "D = Update City names" << endl;
      cout << "T = Update time out"<<endl;
      cout << "E = Exit" << endl;
      cout << ">";
      cin >> userChoice;

      if (userChoice == "A" || userChoice == "a")
	{			//Dr_T challenge Accept a new name for s's home team
	  cout << "****Update Home Team Score module*** " << endl;
	  cout << "\nPlease enter a new name for the home team: ";
	  cin >> newNameA;	//change that home team's default name andchange that home team's default name
	  tOne.setName (newNameA);	//set tOne's data to the new desired name
	  cout << "\nPlease enter a new name for the visitor team: ";
	  cin >> newNameB;
	  tTwo.setName (newNameB);
//cin >> newNameB;
//tOne.setName(newNameB);
	}
      else if (userChoice == "B" || userChoice == "b")
	{
	  cout << "\nUpdate Home Score Module****" << endl;
	  cout << "\nPlease enter a new score for the home team: ";
	  cin >> newScore;
	  cout << "\nPlease enter a new score for the visitor team: ";
	  tOne.setScore (newScore);
	  cin >> newScore;
	  tTwo.setScore (newScore);
	}
      else if (userChoice == "C" || userChoice == "c")
	{
	  cout << "\nUpdate Coach name module****" << endl;
	  cout << "\nPlease enter a new coach name for the home team: ";
	  cin >> newCoachA;
	  tOne.setCoach_Name (newCoachA);
	  cout << "\nPlease enter a new coach name for the visitor team: ";
	  cin >> newCoachB;
	  tTwo.setCoach_Name (newCoachB);
	}
      else if (userChoice == "D" || userChoice == "d")
	{
	  cout << "\nUpdate City name module****" << endl;
	  cout << "\nPlease enter a new city name for the home team: ";
	  cin >> newCityA;
	  tOne.setHome_City(newCityA);
	  cout << "\nPlease enter a new coach name for the visitor team: ";
	  cin >> newCityB;
	  tTwo.setHome_City(newCityB);
	}
     else if(userChoice == "T" || userChoice == "t")
     {
     cout << "\nUpdate City name module****" << endl;
	  cout << "\nEnter new additional timeout: ";
	  cin >> timeout;
	  tOne.setTimeout_Count(timeout);
     }
      else if (userChoice == "E" || userChoice == "e")
	{
	  cout << "Exit chosen." << endl;
	}
      else			//invalid input: default clause
	{
	  cout << "\nInvalid input." << endl;
	  sleep (2);		//wait two seconds, go to the next process
	}
      s.setHome (tOne);		//refresh the data in s to the new updates...
      s.setVisitor (tTwo);
    }
  while (userChoice != "E" && userChoice != "e");


  return 0;
}