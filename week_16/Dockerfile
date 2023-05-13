from ubuntu

RUN apt-get update \
  && apt-get install -y sudo \
  && apt-get install -y curl \
  && apt-get install -y git \
  && apt-get install -y vim \
  && apt-get install -y tmux \
  && DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential libssl-dev zlib1g-dev \
                        libbz2-dev libreadline-dev libsqlite3-dev curl \
                        libncursesw5-dev xz-utils tk-dev libxml2-dev libxmlsec1-dev libffi-dev liblzma-dev

ADD ./config_files/entrypoint.sh /
RUN chmod a+x /entrypoint.sh

RUN echo "root:Docker!" | chpasswd

RUN mkdir -m 0777 /projects
RUN mkdir -m 0777 /config_files
RUN mkdir -m 0777 /pyenv_versions

RUN addgroup --gid 22222 docker

RUN useradd \
  --create-home \
  --shell /bin/bash \
  --uid 11111 \
  --gid 22222 \
  docker-user

RUN echo "docker-user:Docker!" | chpasswd

USER docker-user
WORKDIR /home/docker-user

#RUN mkdir ${HOME}/config_files
RUN mv ${HOME}/.bashrc ${HOME}/.bashrc_orig
RUN ln -s /config_files/.bashrc     ${HOME}/.bashrc
RUN ln -s /config_files/.vimrc      ${HOME}/.vimrc
RUN ln -s /config_files/.tmux.conf  ${HOME}/.tmux.conf

RUN curl https://pyenv.run | bash
#RUN mkdir ${HOME}/.pyenv/versions
#RUN mkdir ${HOME}/projects

RUN ln -s /pyenv_versions/ ${HOME}/.pyenv/versions
RUN ln -s /projects/       ${HOME}/projects
RUN ln -s /config_files/   ${HOME}/config_files

USER root
ENTRYPOINT ["/config_files/entrypoint.sh"]

#USER root
#CMD ["/bin/bash"]
