# Fichier: test_calculator.py

# Importation de la fonction à tester
from calculator import add, subtract, multiply, divide

# Tests pour la fonction d'addition
def test_add():
    assert add(2, 3) == 5
    assert add(-1, 1) == 0
    assert add(-1, -1) == -2

# Tests pour la fonction de soustraction
def test_subtract():
    assert subtract(5, 3) == 2
    assert subtract(1, 1) == 0
    assert subtract(-1, -1) == 0

# Tests pour la fonction de multiplication
def test_multiply():
    assert multiply(2, 3) == 6
    assert multiply(-1, 1) == -1
    assert multiply(-1, -1) == 1

# Tests pour la fonction de division
def test_divide():
    assert divide(6, 3) == 2
    assert divide(-6, 3) == -2
    assert divide(0, 5) == 0

# Test pour vérifier qu'une exception est levée lors d'une division par zéro
import pytest

def test_divide_by_zero():
    with pytest.raises(ValueError):
        divide(5, 0)

# Exemple d'utilisation de fixtures
@pytest.fixture
def sample_numbers():
    return [1, 2, 3, 4, 5]

def test_sum_with_fixture(sample_numbers):
    assert sum(sample_numbers) == 15

# Exemple de test paramétré
@pytest.mark.parametrize("a, b, expected", [
    (1, 2, 3),
    (-1, 1, 0),
    (0, 0, 0),
])
def test_add_parametrized(a, b, expected):
    assert add(a, b) == expected
