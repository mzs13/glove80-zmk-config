#!/bin/bash

set -euo pipefail

IMAGE=glove80-zmk-config-docker
BRANCH="${1:-leader-key}"

docker build -t "$IMAGE" .
docker run -it -v "$PWD:/config" -v "/home/matt/zmk-modules:/zmk-modules" -e UID="$(id -u)" -e GID="$(id -g)" -e BRANCH="$BRANCH" "$IMAGE"
