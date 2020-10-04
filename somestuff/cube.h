#pragma once

#include <vector>
#include <fstream>
#include <deque>
#include "Exceptions.h"


class Cube {
private:
    std::vector<std::vector<char>> top;
    std::vector<std::vector<char>> bottom;
    std::vector<std::vector<char>> right;
    std::vector<std::vector<char>> left;
    std::vector<std::vector<char>> back;
    std::vector<std::vector<char>> front;
    static void resize(std::vector<std::vector<char>>& vec);
    static void rotate_matrix_left(std::vector<std::vector<char>>& vec);
    static void rotate_matrix_right(std::vector<std::vector<char>>& vec);
    std::deque<char> correct_combination_;
    void roll_lineN_left(int N);
    void roll_lineN_right(int N);
    void roll_rowN_up(int N);
    void roll_rowN_down(int N);
public:
    void enter_commands_for_cube(const std::vector<char>& option);
    void random_tangling(int N);

    Cube() = default;

    Cube(Cube const &cube) {
        this->top = cube.top;
        this->bottom = cube.bottom;
        this->left = cube.left;
        this->right = cube.right;
        this->front = cube.front;
        this->back = cube.back;
    }

    bool check_status();
    bool can_be_solved();

    void input(const std::string& f_in);
    void output(const std::string& f_out);

    void rotate_side_up_to_left();
    void rotate_side_up_to_right();

    void rotate_side_down_to_left();
    void rotate_side_down_to_right();

    void rotate_side_left_to_left();
    void rotate_side_left_to_right();

    void rotate_side_forward_to_left();
    void rotate_side_forward_to_right();

    void rotate_side_right_to_left();
    void rotate_side_right_to_right();

    void change_point_of_view_left();
    void change_point_of_view_right();

    void change_point_of_view_up();
    void change_point_of_view_down();

    std::vector<std::vector<char>> get_up_matrix() {
        return this->top;
    }
    std::vector<std::vector<char>> get_down_matrix() {
        return this->bottom;
    }
    std::vector<std::vector<char>> get_right_matrix() {
        return this->right;
    }
    std::vector<std::vector<char>> get_left_matrix() {
        return this->left;
    }
    std::vector<std::vector<char>> get_back_matrix() {
        return this->back;
    }
    std::vector<std::vector<char>> get_forward_matrix() {
        return this->front;
    }

    void get_right_answer();
};