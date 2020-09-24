#include <bits/stdc++.h>
using namespace std;
int dx[]={-1,1,-1,1};
int dy[]={-1,1,1,-1};
void start_game();
void game_mode_1vsPC();
void afisez_configuratia(char M[10][10])
{
    cout<<"  ";
    for(int i=1;i<9;++i) cout<<char(i-1+'A');
    cout<<'\n';
    cout<<'\n';
    for(int i=1;i<9;++i)
    {
        cout<<char(9-i+'0');
        cout<<" ";
        for(int j=1;j<9;++j)
            cout<<M[i][j];
        cout<<" ";
        cout<<char(9-i+'0');
        cout<<'\n';
    }
    cout<<'\n';
    cout<<"  ";
    for(int i=1;i<9;++i) cout<<char(i-1+'A');
    cout<<'\n';
}
void game_mode_1vs1()
{
    char M[10][10];
    for(int i=0;i<10;++i)
        for(int j=0;j<10;++j)
            M[i][j]='#';
    for(int i=1;i<9;++i)
        for(int j=1;j<9;++j)
            if((i+j)%2==0)
                M[i][j]='$';
    string player_1,player_2;
    char lit_1,lit_2;
    cout<<"Introduceti nume player1 : ";
    cin>>player_1;
    cout<<"Introduceti o litera care sa va reprezinte piesele : ";
    cin>>lit_1;
    for(int i=1;i<3;++i)
        for(int j=1;j<9;++j)
            if((i+j)%2==0)
                M[i][j]=lit_1;
    cout<<"Introduceti nume player2 : ";
    cin>>player_2;
    cout<<"Introduceti o litera diferita de cea aleasa de player1 care sa va reprezinte piesele  : ";
    cin>>lit_2;
    for(int i=7;i<9;++i)
        for(int j=1;j<9;++j)
            if((i+j)%2==0)
                M[i][j]=lit_2;
    int runda=1;
    while(1)
    {
        cout<<'\n';
        cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<"        ROUND "<<runda<<"        "<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
        cout<<'\n'<<'\n';
        afisez_configuratia(M);
        cout<<'\n'<<'\n';
        cout<<"Este randul ca playerul ";
        if(runda&1) cout<<player_1;
        else cout<<player_2;
        cout<<" sa mute\n";
        cout<<'\n';
        char cur_lit;
        if(runda&1) cur_lit=lit_1;
        else cur_lit=lit_2;
        char adv_lit;
        if(runda&1) adv_lit=lit_2;
        else adv_lit=lit_1;
        while(1)
        {
            cout<<"Pozitia pieselor tale pe care le poti muta : ";
            for(int i=1;i<9;++i)
                for(int j=1;j<9;++j)
                    if(M[i][j]==cur_lit)
                    {
                        bool ok=1;
                        for(int k=0;k<4;++k)
                        {
                            int xx=i+dx[k];
                            int yy=j+dy[k];
                            if(M[xx][yy]=='$') ok=0;
                        }
                        if(!ok)
                        {
                            cout<<char(j-1+'A');
                            cout<<char(9-i+'0');
                            cout<<' ';
                        }
                    }
            cout<<'\n';
            cout<<"Selecteaza una dintre pozitiile pieselor tale pentru a muta : ";
            char a,b;
            cin>>a>>b;
            if(M[9-(b-'0')][a-'A'+1]!=cur_lit)
            {
                cout<<"Ai gresit piesa baiatul meu :)) \n";
                continue;
            }
            bool ok=1;
            for(int i=0;i<4;++i)
            {
                int xx=9-(b-'0')+dx[i];
                int yy=a-'A'+1+dy[i];
                if(M[xx][yy]!='$') continue;
                ok=0;
            }
            if(ok)
            {
                cout<<"Ai gresit piesa baiatul meu :)) \n";
                continue;
            }
            cout<<"Acestea sunt pozitiile in care poti muta : ";
            for(int i=0;i<4;++i)
            {
                int xx=9-(b-'0')+dx[i];
                int yy=a-'A'+1+dy[i];
                if(M[xx][yy]!='$') continue;
                cout<<char(yy-1+'A');
                cout<<char(9-xx+'0');
                cout<<' ';
                ok=0;
            }
            cout<<'\n';
            cout<<"Selecteaza pozitia unde doresti sa muti piesa : ";
            char c,d;
            cin>>c>>d;
            if(M[9-(d-'0')][c-'A'+1]!='$')
            {
                cout<<"Ai selectat o pozitie gresita \n";
                continue;
            }
            swap(M[9-(d-'0')][c-'A'+1],M[9-(b-'0')][a-'A'+1]);
            break;
        }

        /// de aici trebuie sa continui
        bool Scot[10][10];
        for(int i=0;i<10;++i)
            for(int j=0;j<10;++j)
                Scot[i][j]=0;
        int nr_piese_care_pot_fi_scoase=0;
        for(int i=1;i<9;++i)
            for(int k=1;k<9;++k)
                if(M[i][k]==adv_lit)
        {
            bool ok=1;
            bool adversar=0;
            for(int j=0;j<4;++j)
            {
                int xx=i+dx[j];
                int yy=k+dy[j];
                if(M[xx][yy]=='$') ok=0;
                if(M[xx][yy]==cur_lit) adversar=1;
            }
            if(ok&&adversar)
            {
                nr_piese_care_pot_fi_scoase++;
                Scot[i][k]=1;
            }
        }
        while(nr_piese_care_pot_fi_scoase>0)
        {
            cout<<'\n';
            afisez_configuratia(M);
            cout<<'\n'<<'\n';

            cout<<"Acestea sunt piesele adversarului care pot fi scoase de pe tabla : ";
            for(int i=1;i<9;++i)
                for(int j=1;j<9;++j)
                    if(Scot[i][j]==1)
            {
                cout<<char(j-1+'A');
                cout<<char(9-i+'0');
                cout<<' ';
            }
            cout<<'\n';
            cout<<"Doresti sa scoti vreo piesa de pe tabla? \n";
            cout<<"Introdu pozitia piesei pe care doresti sa o scoti prima data sau NU daca nu doresti sa scoti vreo piesa : ";
            char aa,bb;
            cin>>aa>>bb;
            if(aa=='N'&&bb=='U') break;
            if(Scot[9-(bb-'0')][aa-'A'+1]==0)
            {
                cout<<"Pozitie incorecta ):\n";
                continue;
            }
            Scot[9-(bb-'0')][aa-'A'+1]=0;
            M[9-(bb-'0')][aa-'A'+1]='$';
            nr_piese_care_pot_fi_scoase--;
            cout<<'\n';
        }
        int scor_1=0,scor_2=0;
        for(int i=1;i<9;++i)
            for(int j=1;j<9;++j)
                if(M[i][j]==lit_1) scor_1++;
                else if(M[i][j]==lit_2) scor_2++;
        if(!scor_2||!scor_1)
        {
            cout<<'\n';
            cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<"        ROUND "<<runda<<"        "<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
            cout<<'\n'<<'\n';
            cout<<"Jucatorul ";
            if(!scor_2) cout<<player_1;
            else cout<<player_2;
            cout<<" a CASTIGAT!!!\n";
            cout<<"Felicitari castigatorului!!!\n";
            cout<<"Doriti sa continuati sa jucati DA sau NU : ";
            string ans;
            cin>>ans;
            cout<<'\n';
            if(ans=="DA")
            {
                start_game();
                return ;
            }
            else return;
        }

        /// trebuie sa scriu terminalul
        cout<<"Doresti ca meciul sa se termine cu o remiza DA sau NU : ";
        string answer;
        cin>>answer;
        cout<<'\n';
        if(answer=="DA")
        {
            cout<<'\n';
            cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<"        ROUND "<<runda<<"        "<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
            cout<<'\n'<<'\n';
            cout<<"Jocul sa terminat cu o REMIZA!!!\n";
            cout<<"Felicitari ambilor jucatori!!!\n";
            cout<<"Doriti sa continuati sa jucati DA sau NU : ";
            string ans;
            cin>>ans;
            if(ans=="DA")
            {
                start_game();
                return ;
            }
            else return;
        }

        cout<<'\n';
        cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<"        ROUND "<<runda<<"        "<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
        cout<<'\n'<<'\n';
        runda++;
    }
}
void game_mode_1vsPC()
{
    char M[10][10];
    for(int i=0;i<10;++i)
        for(int j=0;j<10;++j)
            M[i][j]='#';
    for(int i=1;i<9;++i)
        for(int j=1;j<9;++j)
            if((i+j)%2==0)
                M[i][j]='$';
    string player_1,player_2="PC";
    char lit_1,lit_2='P';
    cout<<"Introduceti nume player : ";
    cin>>player_1;
    cout<<"Piesele PC-ului sunt reprezentate prin litera P\n";
    cout<<"Introduceti o litera diferita de P care sa va reprezinte piesele  : ";
    cin>>lit_1;
    for(int i=1;i<3;++i)
        for(int j=1;j<9;++j)
            if((i+j)%2==0)
                M[i][j]=lit_1;
    for(int i=7;i<9;++i)
        for(int j=1;j<9;++j)
            if((i+j)%2==0)
                M[i][j]=lit_2;
    int runda=1;
    while(1)
    {
        if(runda&1)
        {
            cout<<'\n';
            cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<"        ROUND "<<runda<<"        "<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
            cout<<'\n'<<'\n';
            afisez_configuratia(M);
            cout<<'\n'<<'\n';
            cout<<"Este randul ca playerul ";
            if(runda&1) cout<<player_1;
            else cout<<player_2;
            cout<<" sa mute\n";
            cout<<'\n';
            char cur_lit;
            if(runda&1) cur_lit=lit_1;
            else cur_lit=lit_2;
            char adv_lit;
            if(runda&1) adv_lit=lit_2;
            else adv_lit=lit_1;
            while(1)
            {
                cout<<"Pozitia pieselor tale pe care le poti muta : ";
                for(int i=1;i<9;++i)
                    for(int j=1;j<9;++j)
                    if(M[i][j]==cur_lit)
                    {
                        bool ok=1;
                        for(int k=0;k<4;++k)
                        {
                            int xx=i+dx[k];
                            int yy=j+dy[k];
                            if(M[xx][yy]=='$') ok=0;
                        }
                        if(!ok)
                        {
                            cout<<char(j-1+'A');
                            cout<<char(9-i+'0');
                            cout<<' ';
                        }
                    }
                cout<<'\n';
                cout<<"Selecteaza una dintre pozitiile pieselor tale pentru a muta : ";
                char a,b;
                cin>>a>>b;
                if(M[9-(b-'0')][a-'A'+1]!=cur_lit)
                {
                    cout<<"Ai gresit piesa baiatul meu :)) \n";
                    continue;
                }
                bool ok=1;
                for(int i=0;i<4;++i)
                {
                    int xx=9-(b-'0')+dx[i];
                    int yy=a-'A'+1+dy[i];
                    if(M[xx][yy]!='$') continue;
                    ok=0;
                }
                if(ok)
                {
                    cout<<"Ai gresit piesa baiatul meu :)) \n";
                    continue;
                }
                cout<<"Acestea sunt pozitiile in care poti muta : ";
                for(int i=0;i<4;++i)
                {
                    int xx=9-(b-'0')+dx[i];
                    int yy=a-'A'+1+dy[i];
                    if(M[xx][yy]!='$') continue;
                    cout<<char(yy-1+'A');
                    cout<<char(9-xx+'0');
                    cout<<' ';
                    ok=0;
                }
                cout<<'\n';
                cout<<"Selecteaza pozitia unde doresti sa muti piesa : ";
                char c,d;
                cin>>c>>d;
                if(M[9-(d-'0')][c-'A'+1]!='$')
                {
                    cout<<"Ai selectat o pozitie gresita \n";
                    continue;
                }
                swap(M[9-(d-'0')][c-'A'+1],M[9-(b-'0')][a-'A'+1]);
                break;
            }

            /// de aici trebuie sa continui
            bool Scot[10][10];
            for(int i=0;i<10;++i)
                for(int j=0;j<10;++j)
                    Scot[i][j]=0;
            int nr_piese_care_pot_fi_scoase=0;
            for(int i=1;i<9;++i)
                for(int k=1;k<9;++k)
                    if(M[i][k]==adv_lit)
            {
                bool ok=1;
                bool adversar=0;
                for(int j=0;j<4;++j)
                {
                    int xx=i+dx[j];
                    int yy=k+dy[j];
                    if(M[xx][yy]=='$') ok=0;
                    if(M[xx][yy]==cur_lit) adversar=1;
                }
                if(ok&&adversar)
                {
                    nr_piese_care_pot_fi_scoase++;
                    Scot[i][k]=1;
                }
            }
            while(nr_piese_care_pot_fi_scoase>0)
            {
                cout<<'\n';
                afisez_configuratia(M);
                cout<<'\n'<<'\n';

                cout<<"Acestea sunt piesele adversarului care pot fi scoase de pe tabla : ";
                for(int i=1;i<9;++i)
                    for(int j=1;j<9;++j)
                        if(Scot[i][j]==1)
                {
                    cout<<char(j-1+'A');
                    cout<<char(9-i+'0');
                    cout<<' ';
                }
                cout<<'\n';
                cout<<"Doresti sa scoti vreo piesa de pe tabla? \n";
                cout<<"Introdu pozitia piesei pe care doresti sa o scoti prima data sau NU daca nu doresti sa scoti vreo piesa : ";
                char aa,bb;
                cin>>aa>>bb;
                if(aa=='N'&&bb=='U') break;
                if(Scot[9-(bb-'0')][aa-'A'+1]==0)
                {
                    cout<<"Pozitie incorecta ):\n";
                    continue;
                }
                Scot[9-(bb-'0')][aa-'A'+1]=0;
                M[9-(bb-'0')][aa-'A'+1]='$';
                nr_piese_care_pot_fi_scoase--;
                cout<<'\n';
            }
            int scor_1=0,scor_2=0;
            for(int i=1;i<9;++i)
                for(int j=1;j<9;++j)
                    if(M[i][j]==lit_1) scor_1++;
                    else if(M[i][j]==lit_2) scor_2++;
            if(!scor_2||!scor_1)
            {
                cout<<'\n';
                cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<"        ROUND "<<runda<<"        "<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
                cout<<'\n'<<'\n';
                cout<<"Jucatorul ";
                if(!scor_2) cout<<player_1;
                else cout<<player_2;
                cout<<" a CASTIGAT!!!\n";
                cout<<"Felicitari castigatorului!!!\n";
                cout<<"Doriti sa continuati sa jucati DA sau NU : ";
                string ans;
                cin>>ans;
                cout<<'\n';
                if(ans=="DA")
                {
                    start_game();
                    return ;
                }
                else return;
            }

            /// trebuie sa scriu terminalul
            cout<<"Doresti ca meciul sa se termine cu o remiza DA sau NU : ";
            string answer;
            cin>>answer;
            cout<<'\n';
            if(answer=="DA")
            {
                cout<<'\n';
                cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<"        ROUND "<<runda<<"        "<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
                cout<<'\n'<<'\n';
                cout<<"Jocul sa terminat cu o REMIZA!!!\n";
                cout<<"Felicitari ambilor jucatori!!!\n";
                cout<<"Doriti sa continuati sa jucati DA sau NU : ";
                string ans;
                cin>>ans;
                if(ans=="DA")
                {
                    start_game();
                    return ;
                }
                else return;
            }

            cout<<'\n';
            cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<"        ROUND "<<runda<<"        "<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
            cout<<'\n'<<'\n';
            runda++;
            continue;
        }
        cout<<'\n';
        cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<"        ROUND "<<runda<<"        "<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
        cout<<'\n'<<'\n';
        afisez_configuratia(M);
        cout<<'\n'<<'\n';
        vector <pair <int,int> > P;
        for(int i=1;i<9;++i)
            for(int j=1;j<9;++j)
                if(M[i][j]=='P')
                    P.push_back(make_pair(i,j));
        random_shuffle(P.begin(),P.end());
        for(int i=0;i<(int)P.size();++i)
        {
            bool ok=1;
            vector <pair <int,int> > mutare;
            for(int j=0;j<4;++j)
            {
                int x=P[i].first+dx[j];
                int y=P[i].second+dy[j];
                if(M[x][y]=='$')
                {
                    ok=0;
                    mutare.push_back(make_pair(x,y));
                }
            }
            if(!ok)
            {
                random_shuffle(mutare.begin(),mutare.end());
                cout<<"PC a mutatat piesa din ";
                cout<<char(P[i].second-1+'A');
                cout<<char(9-P[i].first+'0');
                cout<<" in ";
                cout<<char(mutare[0].second-1+'A');
                cout<<char(9-mutare[0].first+'0');
                cout<<'\n';
                swap(M[P[i].first][P[i].second],M[mutare[0].first][mutare[0].second]);
                break;
            }
        }
        cout<<'\n'<<'\n';
        afisez_configuratia(M);
        cout<<'\n'<<'\n';
        vector <pair <int,int> > Piese_scoase;
        for(int i=1;i<9;++i)
            for(int k=1;k<9;++k)
                if(M[i][k]==lit_1)
            {
                bool ok=1;
                bool adversar=0;
                for(int j=0;j<4;++j)
                {
                    int xx=i+dx[j];
                    int yy=k+dy[j];
                    if(M[xx][yy]=='$') ok=0;
                    if(M[xx][yy]==lit_2) adversar=1;
                }
                if(ok&&adversar) Piese_scoase.push_back(make_pair(i,k));
            }
        if((int)Piese_scoase.size())
        {
            if((int)Piese_scoase.size()==1) cout<<"In urma mutarii efectuate ai ramas fara piesa : ";
            else cout<<"In urma mutarii efectuate ai ramas fara piesele : ";
            for(int i=0;i<(int)Piese_scoase.size();++i)
            {
                cout<<char(Piese_scoase[i].second-1+'A');
                cout<<char(9-Piese_scoase[i].first+'0');
                cout<<' ';
            }
            cout<<'\n';
            cout<<'\n';
        }

        int scor_1=0,scor_2=0;
        for(int i=1;i<9;++i)
            for(int j=1;j<9;++j)
                if(M[i][j]==lit_1) scor_1++;
                else if(M[i][j]==lit_2) scor_2++;
        if(!scor_2||!scor_1)
        {
            cout<<'\n';
            cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<"        ROUND "<<runda<<"        "<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
            cout<<'\n'<<'\n';
            cout<<"Jucatorul ";
            if(!scor_2) cout<<player_1;
            else cout<<player_2;
            cout<<" a CASTIGAT!!!\n";
            cout<<"Felicitari castigatorului!!!\n";
            cout<<"Doriti sa continuati sa jucati DA sau NU : ";
            string ans;
            cin>>ans;
            cout<<'\n';
            if(ans=="DA")
            {
                start_game();
                return ;
            }
            else return;
        }
        runda++;
    }
}
void start_game()
{
    cout<<"Selectati modul in care doriti sa jucati : 1vs1 sau 1vsPC \n";
    string preferinta;
    cin>>preferinta;
    if(preferinta=="1vs1") game_mode_1vs1();
    else if(preferinta=="1vsPC") game_mode_1vsPC();
    else
    {
        cout<<"Ai gresit modul baiatul meu :)))\n";
        start_game();
        return;
    }
}
int main()
{
    start_game();
    return 0;
}
