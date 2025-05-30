#include <stddef.h>
#include "cnf.h"

//
// LOGIN: xkunzm02
//

// Tato funkce je prikladem pouziti funkci create_new_clause, add_literal_to_clause a add_clause_to_formula
// Vysvetleni, co dela, naleznete v zadani
void example_condition(CNF *formula, unsigned num_of_subjects, unsigned num_of_semesters) {
    assert(formula != NULL);
    assert(num_of_subjects > 0);
    assert(num_of_semesters > 0);

    for (unsigned subject_i = 0; subject_i < num_of_subjects; ++subject_i) {
        for (unsigned semester_j = 0; semester_j < num_of_semesters; ++semester_j) {
            // vytvori novou klauzuli
            Clause *example_clause = create_new_clause(num_of_subjects, num_of_semesters);
            // vlozi do klauzule literal x_{i,j}
            add_literal_to_clause(example_clause, true, subject_i, semester_j);
            // vlozi do klauzule literal ~x_{i,j}
            add_literal_to_clause(example_clause, false, subject_i, semester_j);
            // prida klauzuli do formule
            add_clause_to_formula(example_clause, formula);
        }
    }
}

// Tato funkce by mela do formule pridat klauzule predstavujici podminku a)
// Predmety jsou reprezentovany cisly 0, 1, ..., num_of_subjects-1
// Semestry jsou reprezentovany cisly 0, 1, ..., num_of_semesters-1
void each_subject_enrolled_at_least_once(CNF *formula, unsigned num_of_subjects, unsigned num_of_semesters) {
    assert(formula != NULL);
    assert(num_of_subjects > 0);
    assert(num_of_semesters > 0);

    // ZDE PRIDAT KOD

    Clause *clause = create_new_clause(num_of_subjects, num_of_semesters);

    for (int i = 0; i < num_of_subjects-1; i++)
    {
        for (int j = 0; j < num_of_semesters-1; j++)
        {
            add_literal_to_clause(clause, true, i, j);
        }
        add_clause_to_formula(clause, formula);
    }
    
}

// Tato funkce by mela do formule pridat klauzule predstavujici podminku b)
// Predmety jsou reprezentovany cisly 0, 1, ..., num_of_subjects-1
// Semestry jsou reprezentovany cisly 0, 1, ..., num_of_semesters-1
void each_subject_enrolled_at_most_once(CNF *formula, unsigned num_of_subjects, unsigned num_of_semesters) {
    assert(formula != NULL);
    assert(num_of_subjects > 0);
    assert(num_of_semesters > 0);

    // ZDE PRIDAT KOD

    Clause *clause = create_new_clause(num_of_subjects, num_of_semesters);

    for (int i = 0; i < num_of_subjects-1; i++)
    {
        for (int j = 0; j < num_of_semesters-1; j++)
        {
            add_literal_to_clause(clause, true, i, j);
            add_literal_to_clause(clause, false, i, j+1);
        }
        add_clause_to_formula(clause, formula);
    }
}


// Tato funkce by mela do formule pridat klauzule predstavujici podminku c)
// Promenna prerequisities obsahuje pole s poctem prvku rovnym num_of_prerequisities
// Predmety jsou reprezentovany cisly 0, 1, ..., num_of_subjects-1
// Semestry jsou reprezentovany cisly 0, 1, ..., num_of_semesters-1
void add_prerequisities_to_formula(CNF *formula, Prerequisity* prerequisities, unsigned num_of_prerequisities, unsigned num_of_subjects, unsigned num_of_semesters) {
    assert(formula != NULL);
    assert(prerequisities != NULL);
    assert(num_of_subjects > 0);
    assert(num_of_semesters > 0);

    for (unsigned i = 0; i < num_of_prerequisities; ++i) {
        // prerequisities[i].earlier_subject je predmet, ktery by si mel student zapsat v nekterem semestru pred predmetem prerequisities[i].later_subject

        // ZDE PRIDAT KOD

        Clause *clause = create_new_clause(num_of_subjects, num_of_semesters);

        for (int j = 0; j < num_of_semesters-1; j++)
        {
            add_literal_to_clause(clause, false, prerequisities[i].earlier_subject, j);
            add_literal_to_clause(clause, true, prerequisities[i].later_subject, j+1);
        }
    }
}
