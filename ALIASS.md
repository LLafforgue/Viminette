# Raccourci Bash pour compiler automatiquement des fichiers C

Ce guide explique comment créer un raccourci Bash (`CC`) pour compiler automatiquement un fichier `.c` et générer un exécutable, depuis n'importe quel dossier.

---

## **Installation**

### 1. Ouvrir le fichier de configuration Bash
Ouvrez ou créez le fichier `~/.bash_aliases` :
```bash
nano ~/.bash_aliases
```

### 2. Ajouter l'alias ou la fonction

#### Option 1 : Alias simple (pour compiler `main.c` en `test`)
```bash
alias CC='gcc -Wall -Wextra -Werror main.c -o test'
```

#### Option 2 : Fonction flexible (pour compiler n'importe quel fichier `.c`)
```bash
CC() {
    if [ \$# -ne 1 ]; then
        echo "Usage: CC <fichier.c>"
        return 1
    fi
    gcc -Wall -Wextra -Werror "$1" -o "${1%.c}" && \
    echo "Compilation réussie : \${1%.c}" || \
    echo "Échec de la compilation"
}
```

### 3. Recharger la configuration
Exécutez cette commande pour appliquer les changements :
```bash
source ~/.bashrc
```
ou
```bash
source ~/.bash_aliases
```

---

## **Utilisation**

### Avec l'alias
```bash
CC  # Compile toujours main.c et génère l'exécutable "test"
```

### Avec la fonction
```bash
CC main.c  # Compile main.c et génère l'exécutable "main"
CC mon_projet.c  # Compile mon_projet.c et génère l'exécutable "mon_projet"
```

---

## **Vérification**

1. Créez un fichier `main.c` dans un dossier.
2. Exécutez :
   ```bash
   CC main.c
   ```
3. L'exécutable sera généré sous le nom `main` (ou `test` si vous utilisez l'alias).
4. Lancez l'exécutable :
   ```bash
   ./main
   ```

---

## **Personnalisation**

- **Ajouter des flags** : Modifiez la ligne `gcc` pour ajouter d'autres options (ex: `-g` pour le débogage).
- **Gérer plusieurs fichiers** : Si vous voulez compiler plusieurs fichiers `.c`, modifiez la fonction pour accepter plusieurs arguments.

---

## **Dépannage**

- **"Command not found"** : Assurez-vous que `~/.bash_aliases` est bien chargé dans `~/.bashrc`. Ajoutez ces lignes à `~/.bashrc` si nécessaire :
  ```bash
  if [ -f ~/.bash_aliases ]; then
      . ~/.bash_aliases
  fi
  ```
  Puis rechargez avec `source ~/.bashrc`.

- **Problèmes de compilation** : Vérifiez que `gcc` est installé et que le fichier `.c` existe.

---

## **Exemple de fonction avancée**

Pour compiler plusieurs fichiers `.c` et générer un exécutable personnalisé :
```bash
CC() {
    if [ \$# -lt 1 ]; then
        echo "Usage: CC <fichier1.c> [fichier2.c ...] [-o <executable>]"
        return 1
    fi

    output="a.out"
    files=()

    for arg in "\$@"; do
        if [ "\$arg" = "-o" ]; then
            output="\$2"
            shift 2
        else
            files+=("$arg")
        fi
    done

    gcc -Wall -Wextra -Werror "${files[@]}" -o "\$output" && \
    echo "Compilation réussie : \$output" || \
    echo "Échec de la compilation"
}
```
Utilisation :
```bash
CC main.c utils.c -o mon_programme
```

---

## **Licence**

Ce guide est librement inspirable et modifiable.
