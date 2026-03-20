import socket

SERVER_HOST = '127.0.0.1'
SERVER_PORT = 8080

def send_request(message):
    """Cria uma conexão, envia uma mensagem e retorna a resposta."""
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((SERVER_HOST, SERVER_PORT))
            s.sendall(message.encode('utf-8'))

            response_data = b""
            while True:
                # Recebe dados em pedaços (chunks)
                chunk = s.recv(1024)
                if not chunk:
                    break
                response_data += chunk
                # Se o marcador 'END' estiver na resposta, paramos de ler
                if b"END\n" in response_data or b"SUCCESS" in response_data or b"ERROR" in response_data:
                    break

            return response_data.decode('utf-8')
    except ConnectionRefusedError:
        return "ERROR|Nao foi possivel conectar ao servidor. Ele esta rodando?"
    except Exception as e:
        return f"ERROR|Ocorreu um erro: {e}"

def inserir_pessoa():
    """Pede os dados do usuário e envia uma requisição INSERT."""
    nome = input("Digite o nome da pessoa: ")
    idade = input("Digite a idade da pessoa: ")

    if not nome or not idade.isdigit():
        print("Erro: Nome nao pode ser vazio e idade deve ser um numero.")
        return

    request_message = f"INSERT|{nome}|{idade}"
    response = send_request(request_message)
    print(f"\nResposta do Servidor:\n{response}")

def listar_pessoas():
    """Envia uma requisição LIST e exibe o resultado."""
    request_message = "LIST"
    response = send_request(request_message)

    print("\n--- Lista de Pessoas Cadastradas ---")
    clean_response = response.replace("END\n", "").strip()
    if clean_response:
        for linha in clean_response.split('\n'):
            partes = linha.split('|')
            if len(partes) == 2:
                print(f"Nome: {partes[0]}, Idade: {partes[1]}")
    else:
        print("Nenhuma pessoa cadastrada.")
    print("------------------------------------")


def main():
    """Loop principal do menu do cliente."""
    while True:
        print("\n--- Menu Cliente ---")
        print("1 - Inserir Pessoa")
        print("2 - Listar Pessoas")
        print("3 - Sair")
        escolha = input("Escolha uma opcao: ")

        if escolha == '1':
            inserir_pessoa()
        elif escolha == '2':
            listar_pessoas()
        elif escolha == '3':
            print("Saindo...")
            break
        else:
            print("Opcao invalida. Tente novamente.")

if __name__ == '__main__':
    main()