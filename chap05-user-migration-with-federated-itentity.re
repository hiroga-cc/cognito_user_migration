= FederatedIdentityの連携を伴う、UserPoolからUserPoolへのユーザー移行

//abstract{
UserPoolからUserPoolへのユーザー移行、しかもFederated Identityとの連係を保ったまま、という限定的なケースです。
ID・パスワード・外部サービス連係の組み合わせを、クライアント側への影響を最小限に留めて移行する場合には、参考になる箇所が多少なりともあると考えてご紹介します。
//}


おまけとして、筆者が実際に開発したユーザー移行の詳細を記しておきます。
UserPoolからUserPoolへのユーザー移行という、効果が限定的なケースのため、みなさんが実際に体験することはほぼないと考えています。
一方で、UserPoolのユーザー移行に関する最も難易度の高いケースでもあると考えています。

== 背景
UserPoolに電話番号ログインを追加する。


