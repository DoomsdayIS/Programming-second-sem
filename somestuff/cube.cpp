#include <iostream>
#include "cube.h"
#include "algo.h"

void Cube::input(const std::string& f_in) {
    this->correct_combination_.clear();
    resize(top);
    resize(bottom);
    resize(right);
    resize(left);
    resize(back);
    resize(front);
    std::ifstream in(f_in);
    for (int i = 0; i < 9 * 6; i++) {
        char buf;
        int pos;
        in >> buf;
        in >> pos;
        int it_i = (pos - 1) / 3;
        int it_j = pos - it_i * 3 - 1;
        switch (buf) {
            case 'U':
                in >> top[it_i][it_j];
                break;
            case 'D':
                in >> bottom[it_i][it_j];
                break;
            case 'R':
                in >> right[it_i][it_j];
                break;
            case 'L':
                in >> left[it_i][it_j];
                break;
            case 'B':
                in >> back[it_i][it_j];
                break;
            case 'F':
                in >> front[it_i][it_j];
                break;
            default:
                throw my_exception("Error!");
        }
    }
}

void Cube::output(const std::string &f_out) {
    std::ofstream out(f_out);
    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < 3; ++i) {
            out << "  ";
        }
        out << ' ';
        for (int j = 0; j < 3; ++j) {
            out << top[k][j] << ' ';
        }
        out << '\n';
    }

    for (int l = 0; l < 3; ++l) {
        for (int j = 0; j < 3; ++j) {
            out << left[l][j] << ' ';
        }
        out << ' ';
        for (int j = 0; j < 3; ++j) {
            out << front[l][j] << ' ';
        }
        out << ' ';
        for (int j = 0; j < 3; ++j) {
            out << right[l][j] << ' ';
        }
        out << ' ';
        for (int j = 0; j < 3; ++j) {
            out << back[l][j] << ' ';
        }
        out << '\n';
    }

    for (int m = 0; m < 3; ++m) {
        for (int i = 0; i < 3; ++i) {
            out << "  ";
        }
        out << ' ';
        for (int j = 0; j < 3; ++j) {
            out << bottom[m][j] << ' ';
        }
        out << '\n';
    }
}

void Cube::resize(std::vector<std::vector<char>>& vec) {
    vec.resize(3);
    for (int j = 0; j < 3; ++j) {
        vec[j].resize(3, ' ');
    }
}

void Cube::rotate_matrix_right(std::vector<std::vector<char>> &vec) {
    std::vector<std::vector<char>> buf(3, std::vector<char>(3));
    buf = vec;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            vec[i][j] = buf[2 - j][i];
        }
    }
}

void Cube::rotate_matrix_left(std::vector<std::vector<char>> &vec) {
    rotate_matrix_right(vec);
    rotate_matrix_right(vec);
    rotate_matrix_right(vec);
}

void Cube::roll_lineN_left(const int N) {
    std::vector<char> vec(3);
    for (int i = 0; i < 3; ++i) {
        vec[i] = left[N][i];
    }

    for (int i = 0; i < 3; ++i) {
        left[N][i] = front[N][i];
    }

    for (int i = 0; i < 3; ++i) {
        front[N][i] = right[N][i];
    }

    for (int i = 0; i < 3; ++i) {
        right[N][i] = back[N][i];
    }
    for (int i = 0; i < 3; ++i) {
        back[N][i] = vec[i];
    }
}

void Cube::roll_lineN_right(int N) {
    roll_lineN_left(N);
    roll_lineN_left(N);
    roll_lineN_left(N);
}

void Cube::rotate_side_up_to_left() {
    roll_lineN_left(0);
    rotate_matrix_right(top);
}

void Cube::rotate_side_up_to_right() {
    roll_lineN_right(0);
    rotate_matrix_left(top);
}

void Cube::rotate_side_down_to_left() {
    roll_lineN_right(2);
    rotate_matrix_right(bottom);
}

void Cube::rotate_side_down_to_right() {
    roll_lineN_left(2);
    rotate_matrix_left(bottom);
}

void Cube::roll_rowN_down(int N) {
    std::vector<char> vec(3);
    for (int i = 0; i < 3; ++i) {
        vec[i] = bottom[i][N];
    }
    for (int i = 0; i < 3; ++i) {
        bottom[i][N] = front[i][N];
    }
    for (int i = 0; i < 3; ++i) {
        front[i][N] = top[i][N];
    }
    for (int j = 0; j < 3; ++j) {
        top[j][N] = back[2 - j][2 - N];
    }
    for (int i = 0; i < 3; ++i) {
        back[i][2 - N] = vec[2 - i];
    }
}

void Cube::roll_rowN_up(int N) {
    roll_rowN_down(N);
    roll_rowN_down(N);
    roll_rowN_down(N);
}

void Cube::rotate_side_left_to_left() {
    roll_rowN_up(0);
    rotate_matrix_left(left);
}

void Cube::rotate_side_left_to_right() {
    rotate_side_left_to_left();
    rotate_side_left_to_left();
    rotate_side_left_to_left();
}

void Cube::rotate_side_forward_to_left() {
    rotate_matrix_left(front);
    std::vector<char> vec(3);
    for (int i = 0; i < 3; ++i) {
        vec[i] = top[2][i];
    }
    for (int j = 0; j < 3; ++j) {
        top[2][j] = right[j][0];
    }
    for (int k = 0; k < 3; ++k) {
        right[k][0] = bottom[0][2 - k];
    }
    for (int l = 0; l < 3; ++l) {
        bottom[0][l] = left[l][2];
    }
    for (int m = 0; m < 3; ++m) {
        left[m][2] = vec[2 - m];
    }
}

void Cube::rotate_side_forward_to_right() {
    rotate_side_forward_to_left();
    rotate_side_forward_to_left();
    rotate_side_forward_to_left();
}

void Cube::rotate_side_right_to_left() {
    rotate_matrix_left(right);
    roll_rowN_down(2);
}

void Cube::rotate_side_right_to_right() {
    rotate_side_right_to_left();
    rotate_side_right_to_left();
    rotate_side_right_to_left();
}

void Cube::change_point_of_view_right() {
    this->correct_combination_.push_back('C');
    std::vector<std::vector<char>> vec(3, std::vector<char>(3));
    vec = left;
    left = front;
    front = right;
    right = back;
    back = vec;
    rotate_matrix_right(top);
    rotate_matrix_left(bottom);
}

void Cube::change_point_of_view_left() {
    this->correct_combination_.push_back('c');
    change_point_of_view_right();
    change_point_of_view_right();
    change_point_of_view_right();
}

void Cube::change_point_of_view_up() {
    std::vector<std::vector<char>> vec(3, std::vector<char>(3));
    rotate_matrix_right(bottom);
    rotate_matrix_right(bottom);
    vec = bottom;
    bottom = front;
    front = top;
    rotate_matrix_right(back);
    rotate_matrix_right(back);
    top = back;
    back = vec;
    rotate_matrix_right(left);
    rotate_matrix_left(right);
}

void Cube::change_point_of_view_down() {
    change_point_of_view_up();
    change_point_of_view_up();
    change_point_of_view_up();
}

void Cube::random_tangling(int N) {
    for (int i = 0; i < N; ++i) {
        int buf = 1 + random() % 13;
        switch (buf) {
            case 1:
                this->rotate_side_up_to_right();
                break;
            case 2:
                this->rotate_side_up_to_left();
                break;
            case 3:
                this->rotate_side_down_to_right();
                break;
            case 4:
                this->rotate_side_down_to_left();
                break;
            case 5:
                this->rotate_side_left_to_right();
                break;
            case 6:
                this->rotate_side_left_to_left();
                break;
            case 7:
                this->rotate_side_forward_to_right();
                break;
            case 8:
                this->rotate_side_forward_to_left();
                break;
            case 9:
                this->rotate_side_right_to_right();
                break;
            case 10:
                this->rotate_side_right_to_left();
                break;
            case 11:
                this->change_point_of_view_right();
                break;
            case 12:
                this->change_point_of_view_left();
                break;
            case 13:
                this->change_point_of_view_down();
                break;
            case 14:
                this->change_point_of_view_up();
                break;
            default:
                break;
        }
    }
}

void Cube::enter_commands_for_cube(const std::vector<char> &option) {
    for (char i : option) {
        this->correct_combination_.push_back(i);
        switch (i) {
            case 'l':
                this->rotate_side_left_to_right();
                break;
            case 'L':
                this->rotate_side_left_to_left();
                break;
            case 'r':
                this->rotate_side_right_to_right();
                break;
            case 'R':
                this->rotate_side_right_to_left();
                break;
            case 'u':
                this->rotate_side_up_to_left();
                break;
            case 'U':
                this->rotate_side_up_to_right();
                break;
            case 'd':
                this->rotate_side_down_to_left();
                break;
            case 'D':
                this->rotate_side_down_to_right();
                break;
            case 'f':
                this->rotate_side_forward_to_right();
                break;
            case 'F':
                this->rotate_side_forward_to_left();
                break;
            default:
                throw my_exception("Incorrect operand");
        }
    }
}

void Cube::get_right_answer() {
    for (int i = 0; i < this->correct_combination_.size(); ++i) {
        std::cout << this->correct_combination_[i] << ' ';
    }
}

bool Cube::check_status() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (top[i][j] != top[0][0])
                return false;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (bottom[i][j] != bottom[0][0])
                return false;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (left[i][j] != left[0][0])
                return false;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (front[i][j] != front[0][0])
                return false;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (right[i][j] != right[0][0])
                return false;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (back[i][j] != back[0][0])
                return false;
        }
    }

    return true;
}

bool Cube::can_be_solved() {
    Cube cube(*this);
    try {
        my_sol::solve(cube);
    }catch(my_exception& exception) {
        return false;
    }
    return true;
}
