import random
import string

class Node:
    def __init__(self, key, data):
        self.key = key
        self.data = data
        self.next = None

class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size
        self.count = 0
        self.load_factor = 0.7

    def _hash(self, key):
        # Implementação da função de hash personalizada
        hash_value = 0
        for char in str(key):
            hash_value += ord(char)
        return hash_value % self.size

    def _resize(self):
        old_table = self.table
        self.size *= 2
        self.table = [None] * self.size
        self.count = 0
        for head in old_table:
            current_node = head
            while current_node:
                self.insert(current_node.key, current_node.data)
                current_node = current_node.next

    def insert(self, key, data):
        if self.count / self.size > self.load_factor:
            self._resize()
        node = Node(key, data)
        index = self._hash(key)
        if not self.table[index]:
            print("Inserção bem-sucedida.")
            self.table[index] = node
        else:
            current_node = self.table[index]
            while current_node:
                if current_node.key == key:
                    print(f"O valor {data} inserido tem a mesma chave de um valor inserido anteriormente.")  # Atualiza os dados se a chave já existir
                    return
                if not current_node.next:  # Se chegamos ao final da lista, inserimos o novo nó
                    print("Inserção bem-sucedida.")
                    current_node.next = node
                    break
                current_node = current_node.next
        self.count += 1

    def search(self, key):
        index = self._hash(key)
        if self.table[index]:
            current_node = self.table[index]
            while current_node:
                if current_node.key == key:
                    return current_node.data
                current_node = current_node.next
        print("Chave não encontrada")
        return None

    def remove(self, key):
        index = self._hash(key)
        if self.table[index]:
            if self.table[index].key == key:
                self.table[index] = self.table[index].next
                self.count -= 1
                return
            prev_node = self.table[index]
            current_node = prev_node.next
            while current_node:
                if current_node.key == key:
                    prev_node.next = current_node.next
                    self.count -= 1
                    return
                prev_node = current_node
                current_node = current_node.next
        print("Chave não encontrada")

    def show(self):
        empty_table = True
        for i in range(self.size):
            if self.table[i]:
                current_node = self.table[i]
                while current_node:
                    print(f"Key: {current_node.key}, Data: {current_node.data}")
                    current_node = current_node.next
                    empty_table = False

        if empty_table:
            print("Tabela vazia.")

    def get_size(self):
        return self.count

    def destroy(self):
        self.size = 0
        self.table = []
        self.count = 0

    def search_by_data(self, data):
        keys = []
        for i in range(self.size):
            if self.table[i]:
                current_node = self.table[i]
                while current_node:
                    if current_node.data == data:
                        keys.append(current_node.key)
                    current_node = current_node.next
        if keys:
            return keys
        else:
            print("Dados não encontrados")
            return None

    def remove_by_data(self, data):
        keys = self.search_by_data(data)
        if keys:
            for key in keys:
                self.remove(key)
        else:
            print("Dados não encontrados")


def main():
    size = 10  # Inicialmente definimos o tamanho da tabela hash como 10
    hash_table = HashTable(size)

    while True:
        print("\n1. Inserir novo elemento\n2. Pesquisar por chave\n3. Remover por chave\n4. Mostrar a tabela\n5. Destruir a tabela\n6. Pesquisar por dados\n7. Remover por dados\n8. Tamanho da tabela\n9. Sair")
        choice = int(input("Escolha uma opção: "))

        if choice == 1:
            chave = float(input("Insira a chave (um número real entre 0.000001 e 99999999.999999): "))
            if chave > 99999999.999999 or chave < 0.000001:
                print("A chave não está dentro do intervalo.")
            else:
                key = chave
            info = input("Insira os dados (uma string de até 128 caracteres): ")
            if len(info) > 128:
                print("Os dados inseridos excederam o limite de caracteres.") 
            else:
                data = info
            hash_table.insert(key, data)
        elif choice == 2:
            key = float(input("Insira a chave que deseja pesquisar: "))
            result = hash_table.search(key)
            if result is not None:
                print("Dados:", result)
            else:
                print("Chave não encontrada.")
        elif choice == 3:
            key = float(input("Insira a chave que deseja remover: "))
            hash_table.remove(key)
            print("Remoção bem-sucedida.")
        elif choice == 4:
            hash_table.show()
        elif choice == 5:
            hash_table.destroy()
            print("Tabela destruída.")
        elif choice == 6:
            data = input("Insira os dados que deseja pesquisar: ")
            result = hash_table.search_by_data(data)
            if result is not None:
                print("Chaves:", result)
            else:
                print("Dados não encontrados.")
        elif choice == 7:
            data = input("Insira os dados que deseja remover: ")
            hash_table.remove_by_data(data)
            print("Remoção bem-sucedida.")
        elif choice == 8:
            print("Tamanho da tabela hash:", hash_table.get_size())
        elif choice == 9:
            break
        else:
            print("Opção inválida. Por favor, tente novamente.")


if __name__ == "__main__":
    main()