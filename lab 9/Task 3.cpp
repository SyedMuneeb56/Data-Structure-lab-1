#include <iostream>
using namespace std;


class PlayerNode {
public:
    int playerID;
    int score;

    PlayerNode* next;

    
    PlayerNode(int id, int s) {
        playerID = id;
        score = s;
        next = nullptr;
    }
};


class GameSystem {
private:
    PlayerNode* head;
    PlayerNode* currentPlayer;

public:
  
    GameSystem() {
        head = nullptr;
        currentPlayer = nullptr;
    }

   
    void addPlayer(int id, int score) {
        PlayerNode* newPlayer = new PlayerNode(id, score);

       
        if (head == nullptr) {
            head = newPlayer;
            newPlayer->next = head;
            currentPlayer = head;
        }
        else {
            PlayerNode* temp = head;

            
            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = newPlayer;
            newPlayer->next = head;
        }

        cout << "Player " << id << " joined the game." << endl;
    }

   
    void displayPlayers() {
        if (head == nullptr) {
            cout << "No players in the game!" << endl;
            return;
        }

        PlayerNode* temp = head;

        cout << " players in game " << endl;

        do {
            cout << "Player ID: " << temp->playerID
                << " | Score: " << temp->score << endl;

            temp = temp->next;

        } while (temp != head);

        cout << endl;
    }

   
    void nextTurn() {
        if (currentPlayer == nullptr) {
            cout << "No players available!" << endl;
            return;
        }

        cout << "\nCurrent Turn: Player "
            << currentPlayer->playerID << endl;

        currentPlayer = currentPlayer->next;

        cout << "Next Turn: Player "
            << currentPlayer->playerID << endl;
    }

    
    void skipPlayer() {
        if (currentPlayer == nullptr) {
            cout << "No players available!" << endl;
            return;
        }

        cout << "\nPlayer "
            << currentPlayer->next->playerID
            << " is skipped!" << endl;

        
        currentPlayer = currentPlayer->next->next;

        cout << "Now it's Player "
            << currentPlayer->playerID
            << "'s turn." << endl;
    }

    
    void removePlayer(int id) {

        
        if (head == nullptr) {
            cout << "No players in the game!" << endl;
            return;
        }

        PlayerNode* temp = head;
        PlayerNode* prev = nullptr;

       
        if (head->playerID == id && head->next == head) {
            cout << "\nPlayer " << id << " removed." << endl;
            delete head;
            head = nullptr;
            currentPlayer = nullptr;
            return;
        }

        
        if (head->playerID == id) {

            PlayerNode* last = head;

            while (last->next != head) {
                last = last->next;
            }

            last->next = head->next;

            
            if (currentPlayer == head) {
                currentPlayer = head->next;
            }

            temp = head;
            head = head->next;

            cout << "Player " << temp->playerID
                << " removed from the game." << endl;

            delete temp;
            return;
        }

       
        do {
            prev = temp;
            temp = temp->next;

        } while (temp != head && temp->playerID != id);

      
        if (temp == head) {
            cout << "Player not found!" << endl;
            return;
        }

      
        prev->next = temp->next;

        
        if (currentPlayer == temp) {
            currentPlayer = temp->next;
        }

        cout << "Player " << temp->playerID
            << " removed from the game." << endl;

        delete temp;
    }

  
    void checkWinner() {
        if (head == nullptr) {
            cout << "No winner. Game ended." << endl;
            return;
        }

        
        if (head->next == head) {
            cout << "\n===== GAME OVER =====" << endl;
            cout << "Winner is Player "
                << head->playerID
                << " with score "
                << head->score << "!" << endl;
        }
    }

  
    bool gameRunning() {
        return (head != nullptr && head->next != head);
    }
};


int main() {

    GameSystem game;

    
    game.addPlayer(1, 100);
    game.addPlayer(2, 150);
    game.addPlayer(3, 120);
    game.addPlayer(4, 180);

    
    game.displayPlayers();

   
    game.nextTurn();
    game.nextTurn();

    
    game.skipPlayer();

    
    game.removePlayer(2);
    game.displayPlayers();

    game.removePlayer(3);
    game.displayPlayers();

    game.removePlayer(4);
    game.displayPlayers();

    
    game.checkWinner();

    return 0;
}