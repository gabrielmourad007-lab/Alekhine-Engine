#ifndef _MOVE_H_
#define _MOVE_H_

#include "constants.h"
#include <string>

struct move_t {
    int from = 0;
    int to = 0;
    type_t promotion = type_t::EMPTY;

    move_t() = default;
    move_t(int f, int t, type_t promo = type_t::EMPTY) : from(f), to(t), promotion(promo) {}

    static move_t from_uci(const std::string& s) {
        int from = (s[0] - 'a') + (s[1] - '1') * 8;
        int to = (s[2] - 'a') + (s[3] - '1') * 8;
        type_t promo = type_t::EMPTY;
        if (s.size() >= 5) {
            switch(s[4]) {
                case 'q': {
                    promo = type_t::QUEEN;
                    break;
                }
                case 'r': {
                    promo = type_t::ROOK;
                    break;
                }
                case 'b': {
                    promo = type_t::BISHOP;
                    break;
                }
                case 'n': {
                    promo = type_t::KNIGHT;
                    break;
                }
                default: {
                    break;
                }
            }
        }
        return move_t(from, to , promo);
    }
    std::string to_uci() const {
        std::string s;
        s += char('a' + from % 8);
        s += char('1' + from / 8);
        s += char('a' + to % 8);
        s += char ('1' + to / 8);
        if (promotion == type_t::QUEEN) {
            s += 'q';
        }
        else if ( promotion == type_t::ROOK ) {
            s += 'r';
        }
        else if ( promotion == type_t::BISHOP) {
            s += 'b';
        }
        else if ( promotion == type_t::KNIGHT) {
            s += 'n';
        }
        return s;
    }
};

#endif