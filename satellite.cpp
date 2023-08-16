#include <iostream>
#include <vector>

class Spacecraft {
private:
    int x, y, z;
    char direction;

public:
    Spacecraft(int initialX, int initialY, int initialZ, char initialDirection)
        : x(initialX), y(initialY), z(initialZ), direction(initialDirection) {}

    void move_forward() {
        if (direction == 'N') y++;
        else if (direction == 'S') y--;
        else if (direction == 'E') x++;
        else if (direction == 'W') x--;
        else if (direction == 'U') z++;
        else if (direction == 'D') z--;
    }

    void move_backward() {
        if (direction == 'N') y--;
        else if (direction == 'S') y++;
        else if (direction == 'E') x--;
        else if (direction == 'W') x++;
        else if (direction == 'U') z--;
        else if (direction == 'D') z++;
    }

    void turn_left() {
        if (direction == 'N') direction = 'W';
        else if (direction == 'S') direction = 'E';
        else if (direction == 'E') direction = 'N';
        else if (direction == 'W') direction = 'S';
    }

    void turn_right() {
        if (direction == 'N') direction = 'E';
        else if (direction == 'S') direction = 'W';
        else if (direction == 'E') direction = 'S';
        else if (direction == 'W') direction = 'N';
    }

    void turn_up() {
        if (direction == 'N' || direction == 'S' || direction == 'E' || direction == 'W') {
            direction = 'U';
        }
    }

    void turn_down() {
        if (direction == 'U') {
            direction = 'N';
        } else if (direction == 'N' || direction == 'S' || direction == 'E' || direction == 'W') {
            direction = 'D';
        }
    }

    void execute_commands(const std::vector<char>& commands) {
        for (char command : commands) {
            if (command == 'f') move_forward();
            else if (command == 'b') move_backward();
            else if (command == 'l') turn_left();
            else if (command == 'r') turn_right();
            else if (command == 'u') turn_up();
            else if (command == 'd') turn_down();
        }
    }

    void print_final_position() {
        std::cout << "Final Position: (" << x << ", " << y << ", " << z << ")\n";
        std::cout << "Final Direction: " << direction << "\n";
    }
};

int main() {
    int initialX = 0, initialY = 0, initialZ = 0;
    char initialDirection = 'N';
    std::vector<char> commands = {'f', 'r', 'u', 'b', 'l'};

    Spacecraft chandrayaan(initialX, initialY, initialZ, initialDirection);
    chandrayaan.execute_commands(commands);
    chandrayaan.print_final_position();

    return 0;
}
