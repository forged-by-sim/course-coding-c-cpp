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
    Suit suit;           // Suit of the card (Hearts, Diamonds, etc.)
    short pip;           // Pip value (2-10 for numbers, 11=J, 12=Q, 13=K, 14=A)
} Card;

// Function to initialize a standard 52-card deck with all suit and pip combinations
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

// Fisher-Yates shuffle algorithm to randomize the deck
void shuffle_deck(Card deck[]) {
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Evaluates a 7-card hand and classifies it by matching pip counts
// Returns an integer code for the type of hand detected
// 0 = No Pair, 1 = One Pair, 2 = Two Pair, 3 = Three of a Kind, 4 = Full House, 5 = Four of a Kind
int evaluate_hand(Card hand[]) {
    int pip_counts[15] = {0}; // Index 2-14 tracks pip frequency for each value
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
    srand(time(NULL)); // Seed random number generator with system time

    Card deck[DECK_SIZE];
    Card hand[HAND_SIZE];

    long counts[6] = {0}; // Array to track frequency of each hand type

    // Run Monte Carlo simulation of one million hands
    for (int trial = 0; trial < NUM_TRIALS; trial++) {
        init_deck(deck);          // Reset and initialize deck
        shuffle_deck(deck);      // Shuffle the deck randomly

        // Deal first 7 cards from shuffled deck as a hand
        for (int i = 0; i < HAND_SIZE; i++) {
            hand[i] = deck[i];
        }

        int result = evaluate_hand(hand); // Classify the hand
        counts[result]++;                // Increment the count for the hand type
    }

    const char *labels[] = {"No Pair", "One Pair", "Two Pair", "Three of a Kind", "Full House", "Four of a Kind"};

    printf("\n--- Monte Carlo Simulation of 1M Hands ---\n");
    for (int i = 0; i < 6; i++) {
        printf("%s: %.6f\n", labels[i], (double)counts[i] / NUM_TRIALS);
    }

    return 0;
}
