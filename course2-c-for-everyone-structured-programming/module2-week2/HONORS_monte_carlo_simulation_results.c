#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TRIALS 1000000
#define DECK_SIZE 52
#define HAND_SIZE 7

// Enum for suits
typedef enum {HEARTS, DIAMONDS, CLUBS, SPADES} Suit;

// Struct for card
typedef struct {
    Suit suit;
    short pip;  // 2 through 14 (J=11, Q=12, K=13, A=14)
} Card;

// Function to initialize a deck
void init_deck(Card deck[]) {
    int index = 0;
    for (int s = 0; s < 4; s++) {
        for (int p = 2; p <= 14; p++) {
            deck[index].suit = (Suit)s;
            deck[index].pip = p;
            index++;
        }
    }
}

// Function to shuffle a deck
void shuffle_deck(Card deck[]) {
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to count hand type
int evaluate_hand(Card hand[]) {
    int pip_counts[15] = {0}; // Index 2-14 used
    for (int i = 0; i < HAND_SIZE; i++) {
        pip_counts[hand[i].pip]++;
    }

    int pairs = 0, threes = 0, fours = 0;
    for (int i = 2; i <= 14; i++) {
        if (pip_counts[i] == 4) fours++;
        else if (pip_counts[i] == 3) threes++;
        else if (pip_counts[i] == 2) pairs++;
    }

    if (fours) return 5;
    if (threes && pairs) return 4;
    if (threes) return 3;
    if (pairs == 2) return 2;
    if (pairs == 1) return 1;
    return 0;
}

int main() {
    srand(time(NULL));

    Card deck[DECK_SIZE];
    Card hand[HAND_SIZE];

    long counts[6] = {0}; // 0=no pair, 1=one pair, ..., 5=four of a kind

    for (int trial = 0; trial < NUM_TRIALS; trial++) {
        init_deck(deck);
        shuffle_deck(deck);

        for (int i = 0; i < HAND_SIZE; i++) {
            hand[i] = deck[i];
        }

        int result = evaluate_hand(hand);
        counts[result]++;
    }

    const char *labels[] = {"No Pair", "One Pair", "Two Pair", "Three of a Kind", "Full House", "Four of a Kind"};

    printf("\n--- Monte Carlo Simulation of 1M Hands ---\n");
    for (int i = 0; i < 6; i++) {
        printf("%s: %.6f\n", labels[i], (double)counts[i] / NUM_TRIALS);
    }

    return 0;
}
