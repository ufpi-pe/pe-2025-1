# Uma Instrodução a Sistemas de Arquivos de Sistemas Computacionais

## Conceitos Fundamentais
1. **Propósito dos Arquivos**:
   - Armazenar informações de forma persistente (além do espaço de endereçamento do processo)
   - Permitir compartilhamento entre múltiplos processos
   - Manter dados após o término do processo ou falhas do sistema

2. **Abstração do Arquivo**:
   - Unidade lógica de informação independente do processo
   - Gerida pelo sistema operacional (parte do sistema de arquivos)
   - Modela o armazenamento em disco de forma análoga ao espaço de endereçamento na RAM

## Interface do Usuário
### 1. Nomeação de Arquivos
- **Formatos**:
  - Sistemas UNIX: diferenciam maiúsculas/minúsculas (ex: `maria`, `Maria`, `MARIA` são arquivos distintos)
  - Windows (FAT): não diferencia maiúsculas/minúsculas
- **Extensões**:
  - Convencionais (UNIX) ou obrigatórias (Windows)
  - Exemplos: `.txt` (texto), `.jpg` (imagem), `.pdf` (documento)

### 2. Estrutura de Arquivos
- **Tipos**:
  1. **Sequência de bytes** (UNIX/Windows): sem estrutura interna
  2. **Sequência de registros fixos** (legado: cartões perfurados)
  3. **Árvore de registros** (chaveada, usado em mainframes)

### 3. Tipos de Arquivos
- **Regulares**: dados do usuário
- **Diretórios**: estrutura do sistema de arquivos
- **Especiais**:
  - **Caracteres**: dispositivos de E/S serial (terminais)
  - **Blocos**: discos

### 4. Operações Básicas
- `create`, `delete`, `open`, `close`
- `read`, `write`, `append`
- `seek` (acesso aleatório)
- `get/set attributes` (metadados)
- `rename`

## Diretórios
### 1. Hierarquia
- **Estrutura**:
  - **Único nível**: limitado (ex: dispositivos embarcados)
  - **Hierárquico**: árvore de diretórios (padrão moderno)
- **Caminhos**:
  - **Absoluto**: começa na raiz (ex: `/usr/ast/caixapostal`)
  - **Relativo**: baseado no diretório atual (ex: `cp ../lib/dictionary .`)

### 2. Entradas Especiais
- `.` (diretório atual)
- `..` (diretório pai)

### 3. Operações com Diretórios
- `create`, `delete`, `opendir`, `closedir`
- `readdir`, `rename`
- `link` (hard link) e `unlink`
- **Ligações simbólicas**: apontam para nomes de arquivos (permitem cross-device)

## Implementação
### 1. Atributos (Metadados)
- **Exemplos**:
  - Proteção (permissões)
  - Timestamps (criação, modificação)
  - Tamanho atual/máximo
  - Flags (oculto, somente leitura)

### 2. Exemplo Prático
- **Programa de cópia em UNIX**:
  - Usa `open`, `read`, `write`, `close`
  - Buffer de 4KB para eficiência
  - Verificação de erros mínima

## Sistemas de Arquivos Modernos
- **Windows**: NTFS (suporta Unicode, permissões avançadas)
- **UNIX/Linux**: ext4, XFS, etc.
- **FAT**: legado (simples, para dispositivos)

## Conclusão
Sistemas de arquivos fornecem abstrações críticas para:
- **Persistência**: dados sobrevivem ao processo
- **Organização**: hierarquia de diretórios
- **Compartilhamento**: acesso controlado por múltiplos processos
- **Eficiência**: operações de E/S otimizadas

A implementação varia entre sistemas, mas os conceitos fundamentais (arquivos como sequências de bytes, diretórios hierárquicos e operações básicas) são universais.
