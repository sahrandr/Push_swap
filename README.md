*This project has been created as part of the 42 curriculum by sahrandr, <login2>.*

## Description
`push_swap` trie une pile d'entiers avec un ensemble limité d'opérations (`sa`, `pb`, `ra`, etc.).
Le projet implémente 4 stratégies:
- Simple: O(n²)
- Medium: O(n*sqrt(n))
- Complex: O(n log n)
- Adaptive: choisit selon le désordre initial

Le désordre est calculé avant tout mouvement comme le ratio d'inversions sur le total des paires.

## Instructions
### Compilation
- `make` : compile `push_swap`
- `make bonus` : compile `checker`
- `make clean` / `make fclean` / `make re`

### Exécution
- `./push_swap 3 2 1`
- `./push_swap --simple 3 2 1`
- `./push_swap --medium 3 2 1`
- `./push_swap --complex 3 2 1`
- `./push_swap --adaptive 3 2 1`
- `./push_swap --bench --adaptive 3 2 1`

Le mode `--bench` affiche sur `stderr`:
- disorder (%)
- stratégie + classe de complexité
- nombre total d'opérations
- compte par type d'opération

## Algorithm choices and justification
### 1) Simple O(n²)
Méthode par extraction de maximum: on remonte le max de `a`, on pousse vers `b`, puis on reconstruit `a`.
Le coût est quadratique en nombre d'opérations.

### 2) Medium O(n*sqrt(n))
Tri par chunks: division des index en ~`sqrt(n)` blocs, envoi des valeurs de chaque bloc vers `b`, puis remontée ordonnée.
Le coût visé suit `O(n*sqrt(n))` dans le modèle push_swap.

### 3) Complex O(n log n)
Radix binaire sur les index compressés: partition bit par bit entre `a` et `b`.
Le nombre d'opérations suit `O(n log n)` (log base 2 sur la plage d'index).

### 4) Adaptive
Seuils:
- disorder < 0.2 -> simple
- 0.2 <= disorder < 0.5 -> medium
- disorder >= 0.5 -> complex

Rationale: faible désordre favorise une méthode simple, désordre moyen favorise les chunks, désordre élevé favorise radix.

## Resources
- 42 subject (Push_swap)
- Knuth, *The Art of Computer Programming* (sorting)
- Visualgo / articles de complexité algorithmique

## AI usage
L'IA a été utilisée pour:
- relire la conformité du parsing (`--simple`, `--medium`, `--complex`, `--adaptive`, `--bench`)
- vérifier la cohérence du mode benchmark
- proposer des corrections de structure sans changer la logique centrale

Toutes les modifications ont été relues, testées et comprises avant validation.
